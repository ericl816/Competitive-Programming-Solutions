import java.io.*;
import java.util.*;

class Reader {
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;
    private int http;

    public Reader() {
        din = new DataInputStream(System.in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public Reader(String file_name) throws IOException {
        din = new DataInputStream(new FileInputStream(file_name));
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public String readLine() throws IOException {
        byte[] buf = new byte[64]; // line length
        int cnt = 0, c;
        while ((c = read()) != -1) {
            if (c == '\n') {
                break;
            }
            buf[cnt++] = (byte) c;
        }
        return new String(buf, 0, cnt);
    }

    public int nextInt() throws IOException {
        int ret = 0;
        byte c = read();
        while (c <= ' ') {
            c = read();
        }
        boolean neg = (c == '-');
        if (neg) {
            c = read();
        }
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');

        if (neg) {
            return -ret;
        }
        return ret;
    }

    public long nextLong() throws IOException {
        long ret = 0;
        byte c = read();
        while (c <= ' ') {
            c = read();
        }
        boolean neg = (c == '-');
        if (neg) {
            c = read();
        }
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');
        if (neg) {
            return -ret;
        }
        return ret;
    }

    public double nextDouble() throws IOException {
        double ret = 0, div = 1;
        byte c = read();
        while (c <= ' ') {
            c = read();
        }
        boolean neg = (c == '-');
        if (neg) {
            c = read();
        }

        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');

        if (c == '.') {
            while ((c = read()) >= '0' && c <= '9') {
                ret += (c - '0') / (div *= 10);
            }
        }

        if (neg) {
            return -ret;
        }
        return ret;
    }

    private void fillBuffer() throws IOException {

        bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        if (bytesRead == -1) {
            buffer[0] = -1;
        }
    }

    private byte read() throws IOException {
        if (bufferPointer == bytesRead) {
            fillBuffer();
        }
        return buffer[bufferPointer++];
    }

    public void close() throws IOException {
        if (din == null) {
            return;
        }
        din.close();
    }
}

public class MostlyTalking {
    
	static int N, M, a, b, k, D, ans;
    static ArrayList<ArrayList<Edge>> adj = new ArrayList<ArrayList<Edge>>();
    static int [][] dist = new int [500001][2];
    static PriorityQueue<Vertex> pq = new PriorityQueue<Vertex>();
  
	public static void main (String[] args) throws IOException {
	    Reader r = new Reader();
		N = r.nextInt();
		M = r.nextInt();
		for (int i = 0; i < N; i++) 
			adj.add(new ArrayList<Edge>());
		for (int i = 0; i < M; i++) {
			 a = r.nextInt() - 1;
			 b = r.nextInt() - 1;
			 k = r.nextInt();
			adj.get(a).add(new Edge(b, k, false));
		}
		 D = r.nextInt();
		for (int i = 0; i < D; i++) {
			 a = r.nextInt() - 1;
			 b = r.nextInt() - 1;
			 k = r.nextInt();
			adj.get(a).add(new Edge(b, k, true));
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < 2; j++)
				dist[i][j] = 1 << 30;
		dist[0][0] = 0;
		pq.offer(new Vertex(0, 0, 0));
		while (!pq.isEmpty()) {
			Vertex curr = pq.poll();
			for (Edge e : adj.get(curr.a)) {
				int currcost = curr.b + e.b;
				if (!e.bool && currcost < dist[e.a][curr.c]) {
					dist[e.a][curr.c] = currcost;
					pq.offer(new Vertex(e.a, currcost, curr.c));
				}
				int nextcost = curr.b + e.b;
				if (nextcost < dist[e.a][1] && curr.c == 0 && e.bool) {
					dist[e.a][1] = nextcost;
					pq.offer(new Vertex(e.a, nextcost, 1));
				}
			}
		}
		 ans = Math.min(dist[N - 1][0], dist[N - 1][1]);
		System.out.println(ans != 1 << 30 ? ans : -1);
	}

	public static class Vertex implements Comparable<Vertex> {
		int a, b, c;
		Vertex (int a, int b, int c) {
			this.a = a;
			this.b = b;
			this.c = c;
		}

		@Override
		public int compareTo (Vertex e) {
			return b - e.b;
		}
	}

	public static class Edge {
		int a, b;
		boolean bool;
		Edge (int a, int b, boolean bool) {
			this.a = a;
			this.b = b;
			this.bool = bool;
		}
	}
}