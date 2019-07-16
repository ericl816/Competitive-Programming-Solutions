import java.util.*;
import java.io.*;

public class CCC16MagicSquares {

    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;
    
    public static int val;
    public static int [] rowSum = new int [4];
    public static int [] colSum = new int [4];

public static void main (String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new OutputStreamWriter(System.out));
		
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++) {
				val = readInt();
				rowSum[i] += val;
				colSum[j] += val;
			}
			System.out.println((CheckMagic()) ? "magic" : "not magic");
	}
	
  public static boolean CheckMagic () {
	    if (rowSum[0] == rowSum[1] && rowSum[1] == rowSum[2] && rowSum[2] == rowSum[3] && colSum[0] == colSum[1] && colSum[1] == colSum[2] && colSum[2] == colSum[3] && rowSum[0] == colSum[0]) return true;
	    return false;
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
