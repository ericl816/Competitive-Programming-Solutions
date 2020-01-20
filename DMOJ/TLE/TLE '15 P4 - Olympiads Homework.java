import java.util.*;
import java.io.*;

public class OlympiadsHomework {

	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer st;

	static long N;
	static long MOD = (long) (1e9) + 13;

	public static void main (String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new OutputStreamWriter(System.out));
		
		N = readLong();

		if (N <= 3)
			out.println(1);
		else {
			long sum = 0;
			if (N <= 3)
				sum = 1;
			else {
				sum = power(2, N - 2);
				if (N % 8 == 2 || N % 8 == 6) {
				} else if (N % 8 == 1 || N % 8 == 7) {
					sum = (sum + power(2, (N - 1) / 2 - 1) + MOD) % MOD;
				} else if (N % 8 == 3 || N % 8 == 5) {
					sum = (sum - power(2, (N - 1) / 2 - 1) + MOD) % MOD;
				} else if (N % 8 == 0) {
					sum = (sum + power(2, N / 2 - 1) + MOD) % MOD;
				} else if (N % 8 == 4) {
					sum = (sum - power(2, N / 2 - 1) + MOD) % MOD;
				}
			}
			out.println(sum);
		}
		out.close();
	}
	static long power (long a, long b) {
		if (b == 0)
			return 1;
		if (b == 1)
			return a;
		if (b % 2 == 0)
			return power(a * a % MOD, b / 2);
		return a * power(a * a % MOD, b / 2) % MOD;
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