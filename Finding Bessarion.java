import java.io.*;
import java.util.*;

public class DMOPC_2014_Finding_Bessarion {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static PrintWriter ps = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
  static StringTokenizer st;

  public static void main (String[] args) throws IOException {
    int n = readInt();
    int idx1 = -100, idx2 = -100, idx3 = -100;
    for (int i=0; i<n; i++) {
      String s = readLine();
      if (s.equals("Bayview")) idx1 = i;
      else if (s.equals("Leslie")) idx2 = i;
      else if (s.equals("Bessarion")) idx3 = i;
    }
    if (Math.abs(idx1 - idx3) == 1 && Math.abs(idx2 - idx3) == 1) System.out.println("Y");
    else System.out.println("N");
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