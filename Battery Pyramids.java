import java.io.*;
import java.util.*;

public class BatteryPyramids {

static BufferedReader br;
static PrintWriter out;
static StringTokenizer st;
    
static int T, N, K, temp;
static long temp1, ans;

public static void main(String[] args) throws IOException {
  br = new BufferedReader(new InputStreamReader(System.in));
  out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
  T = readInt();
  for (int i=0; i<T; i++) {
    N = readInt();
    K = readInt();
    N -= K;
    temp1 = 0; ans = 0;
  for (int j=1;; j++) {
    temp = (j * (1 + j)) / 2;
    temp1 += temp;
    if (temp1 <= N) {
      ans = temp1;
    }
    else break;
    }
    System.out.println(ans);
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
