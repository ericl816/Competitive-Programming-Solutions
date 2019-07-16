import java.util.*;
import java.io.*;

public class COCIDeathstar {

	static BufferedReader br;
	static StringTokenizer st;
	static int n, val;
	static int[] arr;

	public static void main (String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		n = readInt();
		arr = new int[n + 1];

		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				val = readInt();
				if (i < j) {
					arr[i] |= val;
					arr[j] |= val;
				}
			}
		}
		for (int i=1; i<=n; i++)
			System.out.print(arr[i] + " ");
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
