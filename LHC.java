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

public class CCO13LHC {

    static int N, i, j;
    static int arr [] = new int [400005];
    static long sum [] = new long [400005];
    static ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
    static long len, cnt; 
    
    public static void DFS(int par, int root) {
      arr[root] = 0; 
      sum[root] = 1;
      for (Integer e : adj.get(root)) {
        if (e != par) {
        DFS(root, e);
        if (len < arr[root] + 1 + arr[e]) {
          len = arr[root] + 1 + arr[e];
          cnt = sum[root] * sum[e];
        }
        else if (len == arr[root] + 1 + arr[e]) cnt += sum[root] * sum[e];
          
          if (arr[root] < 1 + arr[e]) {
            arr[root] = arr[e] + 1;
            sum[root] = sum[e];
          }
          else if (arr[root] == arr[e] + 1) sum[root] += sum[e];
        }
      }
    }

    public static void main (String[] args) throws IOException {
    Reader r = new Reader();
        N = r.nextInt();
        for (int i=1; i<400005; i++) adj.add(new ArrayList<Integer>());
        for (int n=1; n<N; n++) {
		 i = r.nextInt();
		 j = r.nextInt();
		 adj.get(i).add(j);		 
         adj.get(j).add(i);
        }
		DFS(0, 1);
		System.out.println(len + 1 + " " + cnt);
	}
}
