import java.io.*;
import java.util.*;

public class PalinDrone {
  
  public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  public static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
  public static StringTokenizer st;
  
  public static long N, cnt, ans;
  public static String s;
  private static long MOD = 1000000000;
  
  public static long Fpow (long x, long y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    if (y % 2 == 0) return Fpow(x * x, y / 2) % MOD;
    return x * Fpow(x * x, y / 2) % MOD;
  }
  
  public static void main (String [] args) throws IOException {
      s = br.readLine();
      N = 100000;
      if (s.length() < 6) N = Integer.parseInt(s);
      for (long i=1; i<=N; i++) {
        cnt = i;
        if (cnt % 2 == 1) cnt++;
        ans = (long) (ans + 9 * Math.min(MOD, Math.pow(10, cnt / 2 - 1))) % MOD;
      }
      System.out.println((ans + MOD) % MOD);
  }
}