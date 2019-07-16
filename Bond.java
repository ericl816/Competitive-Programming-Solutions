import java.io.*;
import java.util.*;
import java.text.DecimalFormat;

public class COCIBond {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter ps = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;

	static double[] dp;
	static double[][] prob;
	static int n;

	public static void main (String[] args) throws IOException {
            DecimalFormat df = new DecimalFormat("#0.000000");
		n = readInt();
		dp = new double[1 << n];
		prob = new double[n][n];
		for (int i=0; i<1 << n; i++)
			dp[i] = -1;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				prob[i][j] = readInt() / 100.000000d;
			}
		}
		System.out.println((df.format(compute(0, (1 << n) - 1) * 100)));
	}

	private static double compute (int i, int j) {
		if (i == n)
			return 1.000000d;
		if (dp[j] != -1)
			return dp[j];
		double res = 0.0;
		for (int k=0; k<n; k++) {
			if ((j & (1 << k)) > 0) { //If bit is already set
				double next = prob[i][k] * compute(i + 1, j ^ (1 << k)); //Flip bit
				res = Math.max(res, next);
			}
		}
		return dp[j] = res;
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
