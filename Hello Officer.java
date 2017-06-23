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

public class VMSSHelloOfficer {
    
    static int n, m, b, q, x, y, z, query;
    static ArrayList<ArrayList<Edge>> al = new ArrayList<ArrayList<Edge>>();
    static PriorityQueue<Vertex> pq = new PriorityQueue<Vertex>();
    static int dist [] = new int [5001];
    
    public static void main(String[] args) throws IOException {
        Reader r = new Reader();
                
        n = r.nextInt();
        m = r.nextInt();
        b = r.nextInt() - 1; 
        q = r.nextInt();
        for (int i=0; i<n; i++){
            al.add(new ArrayList<Edge>());
            dist[i] = 1 << 30;
        }
            
        for (int i=0; i<m; i++){
            x = r.nextInt() - 1;
            y = r.nextInt() - 1;
            z = r.nextInt();
            al.get(x).add(new Edge(y, z));
            al.get(y).add(new Edge(x, z));
    }
            dist[b] = 0;
             pq.offer(new Vertex(b, 0)); 
         
      while (!pq.isEmpty()) {
            Vertex curr = pq.poll();
            for (Edge e : al.get(curr.a)) {
                if (e.cost + curr.cost < dist[e.a]) {
                  dist[e.a] = Math.min(dist[e.a], e.cost + curr.cost);
                    pq.offer(new Vertex(e.a, dist[e.a]));
                
            }
         }
      }
        for (int j=0; j<q; j++){
            query = r.nextInt() - 1;
            System.out.println((dist[query] == 1 << 30) ? -1 : dist[query]);
      }
   }
    
    
    public static class Edge implements Comparable <Edge> {
        int a, b, cost;
       Edge(int a, int c) {
           this.a = a;
           this.cost = c;
       }
       @Override
       public int compareTo (Edge a) {
           return cost - a.cost;
       }
    }
    
     public static class Vertex implements Comparable <Vertex> {
         int a, cost;
         Vertex (int a, int c) {
         this.a = a;
         this.cost = c;
     }
         @Override
         public int compareTo (Vertex a) {
             return cost - a.cost;
         }
              
    }
}
