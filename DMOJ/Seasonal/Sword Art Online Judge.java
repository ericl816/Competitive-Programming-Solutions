import java.util.*;
import java.io.*;

public class April_Fool_SAOJ {

	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer st;

	final static int MOD = 1000000000;

	public static void main (String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new OutputStreamWriter(System.out));
		int n = readInt();
		long ans = 0;

		for (long i = 1; i <= n; i++)
			ans = (ans + i * i % MOD * i % MOD * i % MOD * i % MOD * i % MOD) % MOD;

		out.println(ans);
		out.close();
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