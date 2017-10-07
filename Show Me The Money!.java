import java.io.*;
import java.util.*;

public class Show_Me_The_Money {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;

	public static String in;
	public static int amount = 0;

	public static void main (String [] args) throws IOException {
		outer:
		for (int i=0; i<5; i++) {
			String in = readLine();
			for (int j=0; j<in.length(); j++) {
			  switch(in.charAt(j)) {
  				case '+':
  					amount++;
  					break;
  				case '-':
  					amount--;
  					if (amount < 0) {
  						System.out.println("OH NOES!");
  						amount = 0;
  						continue outer;
  					}
  					break;
  			}
			}
			System.out.println(amount);	
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