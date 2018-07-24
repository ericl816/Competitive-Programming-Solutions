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

public class GFSSOCPathtoWaterloo {

    static int n, t, node1, node2;
    static ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
    static Queue<Integer> q = new LinkedList<Integer>();
    static HashMap<String, Integer> hm = new HashMap<String, Integer>();
    static String s, s1, s2, split [] = new String[1000];;
    static int [] dist = new int [335];

    public static void SPFA (int start) {
          q.offer(start);
          dist[start] = 0;
          while (!q.isEmpty()) {
            Integer curr = q.poll();
            for (Integer edge : adj.get(curr)) {
                int currcost = dist[curr] + 1;
                if (currcost < dist[edge]) {
                    dist[edge] = currcost;
                    q.offer(edge);
                }
            }
        }
    }

	public static void main (String[] args) throws IOException {
	    Reader r = new Reader ();
        n = r.nextInt(); t = r.nextInt();
        for (int i=0; i<n+2; i++) {
            adj.add(new ArrayList<Integer>());
            dist[i] = 1 << 30;
        }
        hm.put("home", 0); hm.put("Waterloo GO", 1);
        for (int i=0; i<n; i++) hm.put(r.readLine(), i+2);
        for (int i=0; i<t; i++) {
            split = r.readLine().split("-");
            s1 = split[0]; s2 = split[1];
            node1 = hm.get(s1); node2 = hm.get(s2);
            adj.get(node1).add(node2);
            adj.get(node2).add(node1);
        }
        int start = hm.get("home");
        SPFA(start);
        int end = hm.get("Waterloo GO");
        System.out.println(dist[end] != 1 << 30 ? dist[end] : "RIP ACE");
    }
}
