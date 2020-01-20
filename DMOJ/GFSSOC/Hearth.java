import java.io.*;
import java.util.*;

public class Hearth {

  static BufferedReader br;
  static PrintWriter out;
  static StringTokenizer st;
  
  static int N, T;
  static Card arr [];
  
	public static void main (String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
                out = new PrintWriter(new OutputStreamWriter(System.out));
		 N = readInt();
                 T = readInt();
                arr = new Card[N];
		for (int i = 0; i < N; i++) 
			arr[i] = new Card(next(), readInt());
		Arrays.sort(arr);
		for (int i = 0; i < arr.length; i++) {
			for (int j = i + 1; j < arr.length; j++) {
				for (int k = j + 1; k < arr.length; k++) {
					if (arr[i].b + arr[j].b + arr[k].b <= T) {
						System.out.println (arr[i].a + " " + arr[j].a + " " + arr[k].a);
					}
				}
			}
		}
	}

	public static class Card implements Comparable <Card> {
		String a; int b;

		public Card (String a, int b) {
			this.a = a;
			this.b = b;
		}
                @Override
		public int compareTo (Card e) {
			return this.a.compareTo(e.a);
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