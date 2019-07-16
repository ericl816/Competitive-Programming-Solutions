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

public class DMOPC15Contagion {

    static int N, x, y, X, Q;
    static long q;
    static int idx = -1;
    static Edge [] edge;
    static long [] time;
    static boolean [] visited;
    
    public static void main(String[] args) throws IOException {
        Reader r = new Reader ();
             N = r.nextInt();
             edge = new Edge[N];
             time = new long[N];
             visited = new boolean[N];
             
            for (int i=0; i<N; i++){
                x = r.nextInt();
                y = r.nextInt();
                edge[i] = new Edge(x, y);
                time[i] = Long.MAX_VALUE;
            }
               X = r.nextInt() - 1; 
              initialize(X);
              
             Q = r.nextInt();
            for (int i=0; i<Q; i++){
              q = r.nextLong();
                System.out.println(search(q));
            }
    }
    
    public static int search (long target){
        int lo = 0, hi = N - 1;
        while(lo <= hi){
         int mid = (lo + hi) >> 1;
            if (time[mid] <= target) 
                lo = mid + 1;
            else if (time[mid] > target) 
               hi = mid - 1; 
        }
        return lo;
    }
    
    public static void initialize (int X) {
            time[X] = 0; 
                for (int j=0; j<N-1; j++){
                     idx = -1;
                for (int i = 0; i < N; i++)
                   if (!visited[i] && (idx == -1 || time[i] < time[idx]))
                       idx = i;
      
                visited[idx] = true;
                for (int k=0; k<N; k++)
                            time[k] = Math.min(time[k], time[idx] + dist(idx, k));
            }
            Arrays.sort(time);
    }
    
    public static long dist (int i, int j) {
		return (edge[i].x - edge[j].x) * (edge[i].x - edge[j].x) + (edge[i].y - edge[j].y) * (edge[i].y - edge[j].y);
	}
    
    public static class Edge{
        long x, y;
        
        Edge(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}
