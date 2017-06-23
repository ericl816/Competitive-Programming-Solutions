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

public class TSOCAllOutWar {

    public static int N, Q, R, a, b, c;
    public static int [] arr = new int[30005];
    public static Node [] seg = new Node[30005 * 4];

	public static void main (String[] args) throws IOException {
		Reader r = new Reader();
		N = r.nextInt();
		Q = r.nextInt();
		for (int i = 1; i <= N; i++) arr[i] = r.nextInt();
		Build(1, 1, N);
		for (int i = 0; i < Q; i++) {
			 a = r.nextInt();
			 b = r.nextInt();
			 c = r.nextInt();
			Update(1, a, b, c);
			System.out.println(Query(1, a, b) + " " + Query(1, 1, N));
		}
	}

        public static class Node {
		int l, r, min, id;
		Node (int a, int b) {
			this.l = a;
			this.r = b;
		}
	}
        
        public static void PushUp (int idx) {
		seg[idx].min = Math.min(seg[idx << 1].min, seg[idx << 1 | 1].min);
	}

	public static void PushDown (int idx) {
		seg[idx << 1].min = Math.max(0, seg[idx << 1].min - seg[idx].id);
		seg[idx << 1 | 1].min = Math.max(0, seg[idx << 1 | 1].min - seg[idx].id);
		seg[idx << 1].id += seg[idx].id;
		seg[idx << 1 | 1].id += seg[idx].id;
		seg[idx].id = 0;
	}
        
	public static void Build (int idx, int l, int r) {
		seg[idx] = new Node(l, r);
		if (l == r) {
			seg[idx].min = arr[l];
			return;
		}
		int mid = (l + r) >> 1;
		Build(idx << 1, l, mid);
		Build(idx << 1 | 1, mid + 1, r);
		PushUp(idx);
	}

	public static void Update (int idx, int l, int r, int val) {
		if (seg[idx].l == l && seg[idx].r == r) {
			seg[idx].id += val;
			seg[idx].min = Math.max(0, seg[idx].min - val);
			return;
		}
		if (seg[idx].id != 0)
			PushDown(idx);
		int mid = (seg[idx].l + seg[idx].r) >> 1;
		if (r <= mid)
			Update(idx << 1, l, r, val);
		else if (l > mid)
			Update(idx << 1 | 1, l, r, val);
		else {
			Update(idx << 1, l, mid, val);
			Update(idx << 1 | 1, mid + 1, r, val);
		}
		PushUp(idx);
	}

	public static int Query (int idx, int l, int r) {
		if (seg[idx].r == r && seg[idx].l == l)
			return seg[idx].min;
		if (seg[idx].id != 0)
			PushDown(idx);
		int mid = (seg[idx].l + seg[idx].r) >> 1;
		if (r <= mid)
			return Query(idx << 1, l, r);
		if (l > mid)
			return Query(idx << 1 | 1, l, r);
		return Math.min(Query(idx << 1, l, mid), Query(idx << 1 | 1, mid + 1, r));
	}
}
