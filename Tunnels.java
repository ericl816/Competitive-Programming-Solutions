import java.io.*;
import java.util.*;

    public class Tunnels {

        private static Tunnels o = new Tunnels();

            public class Reader {
                private final int BUFFER_SIZE = 1 << 16;
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
            
        private static int MAXN = 200010;
        public static int N, T, A, B, C, cnt;
        public static int [][] dist = new int[MAXN][3];
        public static boolean [] vis = new boolean[MAXN];
        public static ArrayList<ArrayList<Edge>> al = new ArrayList<ArrayList<Edge>>();

	public static void main(String[] args) throws IOException {
	      Reader r = o.new Reader();
	      N = r.nextInt(); T = r.nextInt();
	      for (int i=0; i<N; i++) al.add(new ArrayList<Edge>());
	      for (int i=0; i<N - 1; i++) {
	        A = r.nextInt() - 1;
	        B = r.nextInt() - 1;
	        C = r.nextInt();
	        al.get(A).add(new Edge(B, C));
	        al.get(B).add(new Edge(A, C));
	        cnt += C << 1;
	      }
	      DFS1(0, 0, -1, 0);
	      DFS1(DFS2(0), 0, -1, 1);
              DFS1(DFS2(1), 0, -1, 2);
            for (int i=0; i<N; i++) {
                if (al.get(i).size() == T) System.out.println(i + 1 + " " + (cnt - Math.max(dist[i][1], dist[i][2])));
            }
        }
	
	public static void DFS1(int node, int edge, int prev, int idx) {
	  vis[node] = true;
	  dist[node][idx] = edge;
	  for (Edge next : al.get(node)) {
	    if (next.a == prev) continue;
	    if (!vis[next.a]) DFS1(next.a, next.b + edge, prev, idx);
	  }
	  vis[node] = false;
	}

        public static int DFS2(int idx) {
            int length = 0;
            for (int i=0; i<N; i++) 
                if (dist[i][idx] > dist[length][idx]) length = i;
            return length;
        }

        public static class Edge {
          int a, b;
          Edge (int a_, int b_) {
            this.a = a_;
            this.b = b_;
          }
        }
    }
