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

public class DMOPC15LeleiandContest {

	static long [] arr = new long [200001];
	static long [] tree = new long [800001];
	static long [] lazy = new long [800001];
        static int M, N, Q, query, l, r, x;
        
	public static void main (String[] args) throws IOException {
		Reader in = new Reader();
		M = in.nextInt();
		N = in.nextInt();
		Q = in.nextInt();

		for (int i = 1; i <= N; i++)
			arr[i] = in.nextInt();
		build(1, 1, N, M);
		for (int i = 0; i < Q; i++) {
			query = in.nextInt();
			if (query == 1) {
				 l = in.nextInt();
				 r = in.nextInt();
				 x = in.nextInt();
				update(1, 1, N, l, r, pow(x, M, M), M);
			} 
                        else {
				 l = in.nextInt();
				 r = in.nextInt();
				System.out.println(query(1, 1, N, l, r, M));
			}
		}
	}

	public static long query (int n, int l, int r, int l1, int r1, int MOD) {
		if (l == l1 && r == r1) 
			return tree[n];
		int mid = (l + r) >> 1;
		if (lazy[n] != 0) {
			lazy[n << 1] += lazy[n];
			lazy[n << 1 | 1] += lazy[n];
			tree[n << 1] = (tree[n << 1] + lazy[n] * (mid - l + 1)) % MOD;
			tree[n << 1 | 1] = (tree[n << 1 | 1] + lazy[n] * (r - (mid + 1) + 1)) % MOD;
			lazy[n] = 0;
		}
		if (r1 <= mid)
			return query(n << 1, l, mid, l1, r1, MOD);
		else if (l1 > mid)
			return query(n << 1 | 1, mid + 1, r, l1, r1, MOD);
		return (query(n << 1, l, mid, l1, mid, MOD) + query(n << 1 | 1, mid + 1, r, mid + 1, r1, MOD)) % MOD;
	}

	public static void update (int n, int l, int r, int l1, int r1, long val, int MOD) {
		if (l == l1 && r == r1) {
			long tmp = val;
			tree[n] = (tree[n] + (r - l + 1) * tmp) % MOD;
			lazy[n] += tmp;
			return;
		}
		int mid = (l + r) >> 1;
		if (lazy[n] != 0) {
			lazy[n << 1] += lazy[n];
			lazy[n << 1 | 1] += lazy[n];
			tree[n << 1] = (tree[n << 1] + lazy[n] * (mid - l + 1)) % MOD;
			tree[n << 1 | 1] = (tree[n << 1 | 1] + lazy[n] * (r - (mid + 1) + 1)) % MOD;
			lazy[n] = 0;
		}
		if (r1 <= mid)
			update(n << 1, l, mid, l1, r1, val, MOD);
		else if (l1 > mid)
			update(n << 1 | 1, mid + 1, r, l1, r1, val, MOD);
		else {
			update(n << 1, l, mid, l1, mid, val, MOD);
			update(n << 1 | 1, mid + 1, r, mid + 1, r1, val, MOD);
		}
                
		tree[n] = (tree[n << 1] + tree[n << 1 | 1]) % MOD;
	}

	public static void build (int n, int l, int r, int MOD) {
		if (l == r) {
			tree[n] = pow(arr[l], MOD, MOD);
			return;
		}
		int mid = (l + r) >> 1;
		build(n << 1, l, mid, MOD);
		build(n << 1 | 1, mid + 1, r, MOD);
		tree[n] = (tree[n << 1] + tree[n << 1 | 1]) % MOD;
	}

	public static long pow (long a, long b, long MOD) {
		if (b == 0)
			return 1;
		if (b == 1)
			return a;
		if (b % 2 == 0)
			return pow(a * a % MOD, b >> 1, MOD) % MOD;
		return a * pow(a * a % MOD, b >> 1, MOD) % MOD;
	}
}
