import java.io.*;
import java.util.*;

public class CrossingField {

	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	public static StringTokenizer st;

	private static final int MAXN = 1510;
	public static int N, H;
	public static int xcoor [] = {0, 0, -1, 1};
	public static int ycoor [] = {-1, 1, 0, 0};
	public static boolean flag = false;
	public static boolean vis [][] = new boolean [MAXN][MAXN];
	public static int grid [][] = new int [MAXN][MAXN];
	public static Queue<Coor> q = new LinkedList<Coor>();

	public static void main (String [] args) throws IOException {
		N = readInt();
		H = readInt();
		for (int i=0; i<N; i++) 
			for (int j=0; j<N; j++) 
				grid[i][j] = readInt();
		q.offer(new Coor(0, 0));
		while(!q.isEmpty()) {
			Coor curr = q.poll();
			int currx = curr.x;
			int curry = curr.y;
			if (currx == N - 1 && curry == N - 1) {
				flag = true;
				System.out.println("yes");
			}
			for (int i=0; i<4; i++) {
				int movex = currx + xcoor[i];
				int movey = curry + ycoor[i];
				if (movex < 0 || movey < 0 || vis[movex][movey] || movex >= N || movey >= N || Math.abs((grid[currx][curry] - grid[movex][movey])) > H) continue;
				vis[movex][movey] = true;
				q.offer(new Coor(movex, movey));
			}
		}
		if (!flag) System.out.println("no");
	}

	public static class Coor {
		int x, y;
		
		Coor (int a, int b) {
			this.x = a;
			this.y = b;
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
