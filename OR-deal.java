import java.io.*;
import java.util.*;

public class ORDeal {
    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;
    
    public static long N;
    public static int cnt = 0;
    
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
	    out = new PrintWriter(new OutputStreamWriter(System.out));
        N = readLong();
        while (N > 0) {
            cnt++;
            N /= 2;
    }
    System.out.println(Long.toString((1l << cnt) - 1, 2));
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
