import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.text.DecimalFormat;

public class DMOPC16NegativeFeedback {
    
        static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter ps = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
        static DecimalFormat df;

    public static void main(String[] args) throws IOException {
        df = new DecimalFormat("#0.00");
        st = new StringTokenizer (br.readLine());
        double a = readLong();
        double b = readLong();
        double c = readLong();
       double d = b/c;
       double e = 1+d;
       double f = a*e;
      ps.println(df.format(f));
      ps.close();
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