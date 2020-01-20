import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class TLE16InDebt {

    public static BufferedReader br;
    public static PrintWriter out;
    public static StringTokenizer st;

    public static int val;
    public static String cmd;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
	out = new PrintWriter(new OutputStreamWriter(System.out));
        
        int N;
        int a = 0, b = 0;
        N = readInt();
        int cur = 0;
        for (int i=0; i<N; i++){
            cmd = next();
            val = readInt();
            if (cmd.equals("borrow")){
                cur -= val;
            }
            else {
                cur += val;
            }
            if (-cur > a){
                a = -cur;
                b = i + 1;
            }
        }
        out.println(b);
        out.close();
    }
    public static String next () throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine().trim());
			return st.nextToken();
		}

    public static long readLong () throws IOException {
			return Long.parseLong(next());
		}

    public static int readInt () throws IOException {
			return Integer.parseInt(next());
		}

    public static double readDouble () throws IOException {
			return Double.parseDouble(next());
		}

    public static char readCharacter () throws IOException {
			return next().charAt(0);
		}

    public static String readLine () throws IOException {
			return br.readLine().trim();
		}
}