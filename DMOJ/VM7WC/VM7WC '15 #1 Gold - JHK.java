import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class GoldWeekjhk {

	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static PrintWriter ps = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	private static StringTokenizer st;

	public static void main (String[] args) throws IOException {
		int n = readInt();
		int k = readInt();
		boolean[] isPrime = new boolean[7001];
		int[] dp = new int[7001];

		for (int i = 0; i < 7001; i++)
			dp[i] = 1 << 30;

		isPrime[1] = true;
		dp[0] = 0;

		for (int a = 1; a <= 7000; a++)
			if (isPrime[a] == false) {
				for (int b = a * a; b <= 7000; b += a)
					isPrime[b] = true;
			}

		for (int i = 1; i <= 7000; i++)
			if (!isPrime[i])
				for (int j = 0; j <= 7000; j++)
					if (dp[j] != 1 << 30 && j + i <= 7000)
						dp[j + i] = Math.min(dp[j + i], dp[j] + 1);

		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (dp[i] == k)
				cnt++;

		System.out.println(cnt);
	}

	private static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	private static long readLong () throws IOException {
		return Long.parseLong(next());
	}

	private static int readInt () throws IOException {
		return Integer.parseInt(next());
	}

	private static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}

	private static char readCharacter () throws IOException {
		return next().charAt(0);
	}

	private static String readLine () throws IOException {
		return br.readLine().trim();
	}
}