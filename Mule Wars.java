import java.io.*;
import java.util.*;

public class RTE16J3MuleWars {
  
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static PrintWriter ps = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    public static StringTokenizer st;
  
    public static int T, N, C;
    public static int [] BIT;
    public static HashSet<Integer> lose;
    
    public static void main(String[] args) throws IOException {
      T = readInt();
      for (int i=0; i<T; i++) {
        N = readInt();
        C = readInt();
        lose = new HashSet<Integer>();
        BIT = new int[N + 1];
          for (int j=0; j<C; j++) {
            char op = readCharacter();
            if (op == 'A') {
              int n = readInt();
              int x = readInt();
              if (!lose.contains(x)) Update(x, n);
            }
            else if (op == 'Q') {
              int x = readInt();
             System.out.println(Query(x, x));
            }
            else if (op == 'G') {
              int x = readInt();
              System.out.println(Query(x));
            }
            else if (op == 'L') {
              int x = readInt();
              System.out.println(Query(N - x + 1, N));
            }
            else if (op == 'C') {
              int x = readInt();
              lose.add(x);
              Update(x, -Query(x, x));
            }
          }
      }
    }
    
    public static void Update (int idx, int val) {
        for (; idx < BIT.length; idx += idx & -idx) 
          BIT[idx] += val;
    }

    public static int Query (int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) sum += BIT[idx];
        return sum;
    }

    public static int Query (int a, int b) {
        return Query(b) - Query(a - 1);
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
