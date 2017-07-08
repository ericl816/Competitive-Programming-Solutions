import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.*;

public class ThatsOneHanoiEdTeacher {

    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;
    
    static int MAXN = 1001;
    static int a [] = new int [MAXN];
    static int c [] = new int [3];
    static boolean valid = true; 
    static int curr, next;
    static int peg1 = 1;
    static int peg2 = 0;
    static long cnt = 0;
		
    public static void main(String[] args) throws IOException {
      br = new BufferedReader(new InputStreamReader(System.in));
      out = new PrintWriter(new OutputStreamWriter(System.out));
	    for(int i = 0; i < 3; i++) {
		  c[i] = readInt();
		  curr = MAXN;
		  
		for(int j = 0; j < c[i]; j++) {
		     next = readInt();
		    if (curr <= next) valid = false;
		     a[next] = i;
		      curr = next;
	    	}
	    }

	   for (int i=c[0] + c[1] + c[2]; i>0; i--) {
		if (a[i] == peg1) valid = false;
		else { 
		    cnt = cnt << 1;
		    if (a[i] == peg2) cnt++;
		    else peg2 = peg1;
		    peg1 = 3 - (a[i] + peg1);
		    }
	    }
	    System.out.println((valid ? cnt : "No"));
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
