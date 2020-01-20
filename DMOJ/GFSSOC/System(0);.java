import java.io.*;
import java.util.*;
import java.text.DecimalFormat;

public class System0 {

    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;
    
    static int a;
    static double b, c;
    
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
	out = new PrintWriter(new OutputStreamWriter(System.out));
        DecimalFormat df = new DecimalFormat("#0.000000");
        a = readInt(); b = readDouble(); c = readDouble();
        System.out.println(df.format(-c/(b*a)));
    }
    
        static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}

	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}

}