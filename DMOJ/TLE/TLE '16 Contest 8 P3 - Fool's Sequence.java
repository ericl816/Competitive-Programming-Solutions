import java.io.*;
import java.util.*;

public class TLE16FoolSSequence {

    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;
    
    static int t, n;
    static int [] arr = new int [] {69, 420, 6969, 42069, 69420, 420420, 696969, 4206969, 6942069, 6969420};
    
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
	out = new PrintWriter(new OutputStreamWriter(System.out));
        t = readInt();
        for (int i=0; i<t; i++)
            System.out.println(arr[readInt()-1]);
        
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