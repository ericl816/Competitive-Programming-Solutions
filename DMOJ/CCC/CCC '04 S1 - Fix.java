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

public class Main {

    public static int N;
    public static String s[] = new String[4];

    public static void main(String[] args) throws IOException {
        Reader r = new Reader();
        N = r.nextInt();
        while (N-->0) {
            for (int i=0; i<3; i++) {
                s[i] = r.readLine();
            }
            System.out.println(Check(s) ? "Yes" : "No");
        }
    }

    public static boolean Check (String s[]) {
        if (s[0].startsWith(s[1]) || s[0].startsWith(s[2]) || s[1].startsWith(s[2]) || s[1].startsWith(s[0]) || s[2].startsWith(s[1]) || s[2].startsWith(s[0]) || s[0].endsWith(s[1]) || s[0].endsWith(s[2]) || s[1].endsWith(s[2]) || s[1].endsWith(s[0]) || s[2].endsWith(s[1]) || s[2].endsWith(s[0])) return false;
        return true;
    }
}

    class Pair implements Comparable<Pair> {
        int frq, v;

        @Override
        public String toString () {
            return String.format("(frq: %d, v: %d)", frq, v);
        }

        @Override
        public int compareTo (Pair p) {
            if (Integer.compare (frq, p.frq) == 0)
                return Integer.compare (v, p.v);

            return Integer.compare (p.frq, frq);
        }

        @Override
        public boolean equals (Object o) {
            if (this == o) return true;
            if (o == null || getClass () != o.getClass ()) return false;

            Pair pair = (Pair) o;

            if (frq != pair.frq) return false;
            return v == pair.v;
        }

        @Override
        public int hashCode () {
            int result = frq;
            result = 31 * result + v;
            return result;
        }

        public Pair (int frq, int v) {
            this.frq = frq;
            this.v = v;
        }
    }