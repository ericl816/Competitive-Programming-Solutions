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

public class TLE16PromNight {

    //Is a max-bipartite matching problem 
    //Can use the Ford-Fulkerson algorithm (Runtime of O(Ef)), Edmond Karp algorithm(Runtime of O(VE^2)), or Dinic's algorithm (Runtime of O(V^2E))
    //We can also use the Hungarian algorithm which has a good runtime apparently...
    //This solution uses Ford-Fulkerson's algorithm which has the worst runtime.
    static ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
    static int N, M, t, id, sink, amount, cnt, sum = 0, ans; 
    static int dist [] = new int [210];
    static int arr [] = new int [210];
    static int flow [][] = new int [210][210];
    static Queue<Integer> q = new LinkedList<Integer>();
        
    public static void main(String[] args) throws IOException {
        Reader r = new Reader();
        N = r.nextInt();
        M = r.nextInt();
        for (int i=1; i<=N; i++) {
            t = r.nextInt();
            if (i == 1) cnt = t;
            else flow[0][i] = 1;
        for (int j=0; j<t; j++) {
            id = r.nextInt();
            id += N;
            flow[i][id] = 1;
        if (i == 1) flow[id][N + M + 1] = 1;
      }
    }
      while (true) {
        amount = 0;
        Arrays.fill(dist, 1 << 32);
        Arrays.fill(arr, -1);
        dist[sink] = 0;
        arr[sink] = -1;
        while(!q.isEmpty()) q.remove();
        q.add(sink);
      while(!q.isEmpty()) {
        Integer curr = q.poll();
        if (curr == N + M + 1) break;
        for (int i=0; i<=N + M + 1; i++) {
          if (0 < flow[curr][i] && dist[i] == 1 << 32) {
            dist[i] = dist[curr] + 1;
            arr[i] = curr;
            q.offer(i);
          }
        }
      }
      IncreaseFlow(N + M + 1, 1 << 32);
      if (amount == 0) break; 
      sum += amount;
    }
        ans = cnt - sum;
        System.out.println(ans);
    }
	
    public static void IncreaseFlow(int source, int minresid) {
	  if (source == sink) {
	    amount = minresid;
	    return;
	  }
	  if (arr[source] != -1) {
	    IncreaseFlow(arr[source], Math.min(minresid, flow[arr[source]][source]));
	    flow[source][arr[source]] += amount;
	    flow[arr[source]][source] -= amount;
	  }
       }
    }
