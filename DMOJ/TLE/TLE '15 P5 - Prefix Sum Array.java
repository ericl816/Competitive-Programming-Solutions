import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class PrefixSumArray {

	private static BufferedReader br;
	private static PrintWriter out;
	private static StringTokenizer st;
	private static int N, M;
	private static long[] a;
	private static int MOD = (int) (1e9 + 7);

	public static void main (String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new OutputStreamWriter(System.out));
		
		N = readInt();
		a = new long[N + 1];

		for (int i = 1; i <= N; i++)
			a[i] = readInt();

		M = readInt();
		long[] res = new long[N + 1];
		long fac = -1;

		for (int i = 0; i < N; i++) {
			if (fac == -1) {
				fac = 1;
			} else {
				fac = (fac * (i + 1 + M - 2)) % MOD;
				fac = divideMod(fac, (i + 1 + M - 2 - (M - 1)));
			}
			for (int j = 1 + i; j <= N; j++)
				res[j] = (res[j] + fac * a[j - i]) % MOD;
		}

		for (int i = 1; i <= N; i++)
			out.print(res[i] + " ");
		out.println();
		out.close();
	}

	private static long divideMod (long i, long j) {
		return i * power(j, MOD - 2) % MOD;
	}

	private static long power (long base, long power) {
		if (power == 0)
			return 1;
		if (power == 1)
			return base;
		if (power % 2 == 0)
			return power(base * base % MOD, power / 2);
		return base * power(base * base % MOD, power / 2) % MOD;
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