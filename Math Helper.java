import java.io.*;
import java.util.*;

public class Math_Helper {
  
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    
    public static String equation, a, b;
    public static int T, start, end, coefficient, exponent;
    
    public static void main (String[] args) throws IOException {
        T = readInt();
        while (T-->0) {
            System.out.print("y' = ");
            equation = readLine();
            equation = equation.substring(4);
            if (equation.contains("x")) {
                a = equation.substring(0, equation.indexOf("x"));
                if (a.length() == 0) a = "1";
                else if (a.equals("-")) a = "-1";
                start = Integer.parseInt(a);
                if (equation.contains("^")) {
                    b = equation.substring(equation.indexOf("^") + 1);
                    end = Integer.parseInt(b);
                    coefficient = start * end;
                    exponent = end - 1;
                    if (coefficient == 0) System.out.println(0);
                    else if (exponent == 0) System.out.println(coefficient);
                    else if (coefficient == 1) {
                        if (exponent == 1) System.out.println("x");
                        else System.out.println("x^" + exponent);
                    } 
                    else if (coefficient == -1) {
                        if (exponent == 1) System.out.println("-x");
                        else System.out.println("-x^" + exponent);
                    } 
                    else if (exponent == 1) System.out.println(coefficient + "x");
                    else System.out.println(coefficient + "x^" + exponent);
                } 
                else System.out.println(start);
            } 
            else System.out.println(0);
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