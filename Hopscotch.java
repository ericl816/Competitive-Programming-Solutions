import java.io.*;
import java.util.*;

public class HopScotch {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;

	private static final int MAXN = 200010;
	public static int N, Q, op, x, v, blksize, blknum, ans;
	public static int K [] = new int [MAXN];
	public static int hops [] = new int [MAXN];
	public static int cnt [] = new int [MAXN];

	public static void main (String [] args) throws IOException {
		N = readInt();
		blksize = (int) Math.ceil(Math.sqrt(N));
		for (int i=0; i<N; i++) K[i] = readInt();
		for (int i=1; i<=blksize; i++) Recur(i);
		Q = readInt();
		for (int i=0; i<Q; i++) {
			op = readInt();
			x = readInt();
			if (op == 1) {
				ans = 0;
				while (x < N) {
					ans += cnt[x];
					x = hops[x];
				}
				System.out.println(ans);
			}
			else if (op == 2) {
				v = readInt();
				K[x] = v;
				blknum = (int) Math.ceil((double) x / blksize);
				Recur(blknum);
			}
		}
	}

	public static void Recur (int n) {
		for (int i=Math.min((blksize * n), N - 1); i>=Math.max((blksize * (n - 1)), 0); i--) 
			if (K[i] + i >= Math.min((blksize * n), N)) {
				hops[i] = Math.min(K[i] + i, N);
				cnt[i] = 1;
			}
			else {
				hops[i] = hops[K[i] + i];
				cnt[i] = cnt[K[i] + i] + 1;
			}
	}

	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong () throws IOException {
		return Long.parseLong(next());
	}

	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}

	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}

	static char readCharacter () throws IOException {
		return next().charAt(0);
	}

	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}	