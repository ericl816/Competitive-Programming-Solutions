import java.io.*;
import java.util.*;

public class TLE16DankMeme {
    
    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;
    
    static int n, a;
    static String s, z, w;
    
    public static void main(String[] args) throws IOException {
         br = new BufferedReader(new InputStreamReader(System.in));
	out = new PrintWriter(new OutputStreamWriter(System.out));
        n = readInt();
        for (int i=0; i<n; i++) {
            a = readInt();
            s = Integer.toBinaryString(a);
                   w = s.replace("1", "dank ");
                   z = w.replace("0", "meme ");
                 System.out.println(z);
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