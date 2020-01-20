import java.io.*;
import java.util.*;

public class DMOPC13ARomanticDinner {
    
    static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer st;
		
	public static int M, U, R, Vi, Ti, Fi;
	public static int DP [][] = new int [310][110];
		
    public static void main(String[] args) throws IOException {
      br = new BufferedReader(new InputStreamReader(System.in));
	  out = new PrintWriter(new OutputStreamWriter(System.out));
        M = readInt();
        U = readInt();
        R = readInt();
        for (int i=0; i<R; i++) {
            Vi = readInt();
            Ti = readInt();
            Fi = readInt();
            for (int j=M; j>=Ti; j--) 
                for (int k=U; k>=Fi; k--) 
                    DP[j][k] = Math.max(DP[j][k], Vi + DP[j - Ti][k - Fi]);
        }
        System.out.println(DP[M][U]);
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