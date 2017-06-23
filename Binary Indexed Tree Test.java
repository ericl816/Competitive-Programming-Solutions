import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

//Solution uses a Binary-Indexed Tree/Fenwick Tree and Range Update & Query functions
public class BinaryIndexedTreeTest  {
	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new OutputStreamWriter(System.out));

		int n = readInt();
		int m = readInt();

		int[] val = new int[n];
		for(int i=0; i<n; i++)
			val[i] = readInt();

		long[] BIT1 = new long [n+1];
                long [] BIT2 = new long [100001];
		for(int i=0; i<n; i++) {
			Update(BIT1, i+1, val[i]);
			Update(BIT2, val[i], 1);
		}

                System.out.println("\n");
		for (int i=0; i<m; i++) {
                    char ch = readCharacter();
				if (ch == 'C'){
					int x = readInt() - 1;
					int v = readInt();

					Update(BIT1, x + 1, v - val[x]);
					Update(BIT2, val[x], -1);
					val[x] = v;
					Update(BIT2, val[x], +1);
                                }
                                else if (ch == 'S'){
					int l = readInt();
					int r = readInt();
					System.out.println(Query(BIT1, r) - Query(BIT1, l - 1));
                                }
                                
                                else if (ch == 'Q'){
					int v1 = readInt();
					System.out.println(Query(BIT2, v1));
                                }
		}
	}

	public static void Update(long[] bit, int pos, int end) {
		for(; pos<bit.length; pos += pos &- pos) //X = X & (X-1) strips off the lowest set bit, thus, counting the number of set bits in a number.
			bit[pos] += end;
	}

	public static long Query(long[] bit, int pos) {
		long ans = 0;
		for(; pos>0; pos -= pos &- pos) //X = X & (X-1) strips off the lowest set bit, thus, counting the number of set bits in a number.
			ans += bit[pos];

		return ans;
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
