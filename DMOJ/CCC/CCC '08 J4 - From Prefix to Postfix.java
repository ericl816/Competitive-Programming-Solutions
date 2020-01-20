import java.io.*;
import java.util.*;

public class Main {
    
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static PrintStream ps = new PrintStream(System.out);

    public static boolean isDigit (String a) {
        return (!a.equals("+") && !a.equals("-"));
    }

    public static void main(String[] args) throws IOException {
        String next = "";
        while (!(next = readLine()).equals("0")) {
            if (isDigit(next) && next.length() == 1) {
                System.out.println(next);
                continue;
            }
            String tokens[] = new StringBuilder(next).reverse().toString().split(" ");
            Stack<String> s = new Stack<String>();
            int i = 0;
            String ans = "";
            while (s.size() >= 0 && i < tokens.length) {
                if (isDigit(tokens[i])) s.push(tokens[i]);
                else {
                    ans = s.pop() + " " + s.pop() + " " + tokens[i];
                    s.push(ans);
                }
                i++;
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
    static String readLine () throws IOException {
        return br.readLine().trim();
    }
}