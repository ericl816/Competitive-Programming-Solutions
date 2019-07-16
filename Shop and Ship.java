import java.io.*;
import java.util.*;

public class CCCShopandShip {
    
    public static final char INFINITY = 65535;
    public static int n;            
    public static char[] shipping;   
    public static char[] [] edges;
    public static char[] cost;      

  public static void main (String[] args) throws IOException {
	BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
	n = Integer.parseInt(in.readLine());

	edges = new char [n + 1] [n + 1];
	shipping = new char [n + 1];
	char[] cost = new char [n + 1];

	for (int i = 1 ; i <= n ; i++) {
	    cost [i] = INFINITY;
	    for (int j = 1 ; j <= n ; j++)
		edges [i] [j] = 0;
	}

	int t = Integer.parseInt(in.readLine());
	for (int i = 1 ; i <= t ; i++) {
      StringTokenizer st = new StringTokenizer (in.readLine());
	    int x = Integer.parseInt(st.nextToken());
	    int y = Integer.parseInt(st.nextToken());
	    char c = (char) Integer.parseInt(st.nextToken());
	    if (x >= 1 && x <= n && y >= 1 && y <= n) {
		edges [x] [y] = c;
		edges [y] [x] = c;
	    }
	}

	int k = Integer.parseInt(in.readLine());
	char hold1, hold2;
	for (int i = 0 ; i < k ; i++) {
      StringTokenizer st = new StringTokenizer (in.readLine());
	    hold1 = (char) Integer.parseInt(st.nextToken());
	    hold2 = (char) Integer.parseInt(st.nextToken());
	    if (hold1 >= 1 && hold1 <= n)
		cost [hold1] = hold2;
	}

	int destination = Integer.parseInt(in.readLine());

	Dijkstra (destination);
 
	int min = INFINITY;
	int totalCost = 0;

	for (int i = 1 ; i <= n ; i++) {
	    totalCost = cost [i] + shipping [i];
	    if (totalCost < min)
		  min = totalCost;
	}
	System.out.println (min);
 }

  public static void Dijkstra (int start) {
	boolean[] used = new boolean [n + 1];
	int city, small, count;

	shipping = new char [n + 1];
	for (int i = 1 ; i <= n ; i++) {
	    used [i] = false;
	    shipping [i] = INFINITY;
	}
	shipping [start] = 0;
	count = 0;
	while (count < n) {
	    small = INFINITY;
	    city = 1;
	    for (int i = 1 ; i <= n ; i++) {
		if (!used [i] && shipping [i] < small) {
		    small = shipping [i];
		    city = i;
		}
	}
	    used [city] = true;
	    count++;
	    for (int i = 1 ; i <= n ; i++)
		if (edges [city] [i] > 0 && !used [i])
		    if (shipping [i] > shipping [city] + edges [city] [i])
			shipping [i] = (char) (shipping [city] + edges [city] [i]);
	}
 }
    
public static class Reader {
		BufferedReader br;
		StringTokenizer st;

		public Reader(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public Reader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}
}
