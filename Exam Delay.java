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


public class DMOPC14ExamDelay {
    
  public static int V, E, m, n, d, s, temp, num = 0, time;
  public static double delaytime = 0; 
  public static ArrayList<ArrayList<Edge>> al = new ArrayList<ArrayList<Edge>>();
  public static PriorityQueue<State> pq = new PriorityQueue<State>();
  public static State1 arr [] = new State1[1010];

  public static void main (String[] args) throws IOException {
    Reader r = new Reader();
    V = r.nextInt();
    E = r.nextInt();
    for (int i=0; i<V; i++) al.add(new ArrayList<Edge>());
    for (int i=0; i<E; i++) {
      m = r.nextInt() - 1;
      n = r.nextInt() - 1;
      d = r.nextInt();
      s = r.nextInt();
      al.get(m).add(new Edge(d, s, n));
      al.get(n).add(new Edge(d, s, m));
    }
    for (int i=0; i<V; i++) arr[i] = new State1(Integer.MAX_VALUE, Integer.MAX_VALUE, -1, null);
    arr[0] = new State1(0, 0, -1, null);
    pq.offer(new State(0, 0, 0));
    while (!pq.isEmpty()) {
      State curr = pq.poll();
      for (Edge e : al.get(curr.idx)) {
        double currtime = curr.time + e.dist / (double) e.speed;
        int currinter = curr.inter + 1;
        if (currtime > arr[e.inter].time || (currinter >= arr[e.inter].inter) && arr[e.inter].time == currtime)
          continue;
        arr[e.inter] = new State1(currtime, currinter, curr.idx, e);
        pq.offer(new State(e.inter, currtime, currinter));
      }
    }
    temp = V - 1;
    while (temp > 0) {
      num++;
      delaytime += arr[temp].edge.dist / (0.75 * (arr[temp].edge.speed));
      temp = arr[temp].idx;
    }
    time = (int) (Math.round((delaytime - arr[V - 1].time) * 60));
    System.out.println(num + "\n" + time);
  }

  public static class Edge implements Comparable<Edge> {
    int dist, speed, inter;

    Edge(int a, int b, int c) {
      this.dist = a;
      this.speed = b;
      this.inter = c;
    }

    @Override
    public int compareTo (Edge e) {
      Double t1 = dist / (double) speed;
      Double t2 = e.dist / (double) e.speed;
      return t1.compareTo(t2);
    }
  }

  public static class State implements Comparable<State> {
    int idx, inter;
    double time;

    State(int a, double b, int c) {
      this.idx = a;
      this.time = b;
      this.inter = c;
    }

    @Override
    public int compareTo (State e) {
      return new Double(time).compareTo(e.time);
    }
  }
  
  public static class State1 implements Comparable<State1> {
    int inter, idx;
    double time;
    Edge edge;
    
    State1(double a, int b, int c, Edge d) {
      this.time = a;
      this.inter = b;
      this.idx = c;
      this.edge = d;
    }

    @Override
    public int compareTo (State1 e) {
      return new Double(time).compareTo(e.time);
    }
  }
}
