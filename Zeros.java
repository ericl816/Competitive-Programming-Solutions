import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class DMOPC16Zeros {
                
    public static BufferedReader br;
    public static PrintWriter out;
    public static StringTokenizer st;
    public static long a, b;
    public static long min = 1, min1 = 1;;
    public static long max = Long.MAX_VALUE, max1 = Long.MAX_VALUE;
   
        public static long Numofzeros(long n) {
        long a = 0;
        for (long i=5; n/i>=1; i *= 5)
          a += n/i;
        return a;
        }
         
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
	out = new PrintWriter(new OutputStreamWriter(System.out));
        a = readLong();
        b = readLong();
        while (min <= max){
        long mid = (min + max)/2;
        if (Numofzeros(mid) < a) {
            min = mid+1;
        }
        else max = mid-1;
    }
      
    while(min1 <= max1) {
        long mid = (min1 + max1)/2;
        if (Numofzeros(mid) <= b) {
            min1 = mid+1;
        }
        else max1 = mid-1;
    }
    long solution = min1 - min;
        System.out.println(solution);
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
