import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;
    
    static String a, b, c, d;
    static int n;
    static boolean yes;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
	out = new PrintWriter(new OutputStreamWriter(System.out));
        
       a = next();
       c = a.replace("-", "");
       n = readInt ();
       for (int i=0; i<n; i++) {
           b = next();
           yes = true;
           d = b.replace("-", "");
             if (!d.contains(c)) {
            yes = false;
            System.out.println("no");
            continue;
             }
          if (yes) System.out.println("yes");
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