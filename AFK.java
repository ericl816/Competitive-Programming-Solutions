import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class DMOPC2013Contest1P4AFK {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;

	static char [][] grid;
	static boolean [][] visited;
	static int[] movex = {0, 0, -1, 1};
	static int[] movey = {-1, 1, 0, 0};

	public static void main (String[] args) throws IOException {
		for (int z = readInt(); z > 0; z--) {
			int l = readInt();
			int w = readInt();
			grid = new char[w][l];
			int sx = 0, sy = 0, ex = 0, ey = 0;
			for (int i = 0; i < w; i++) {
				char [] ch = readLine().toCharArray();
				for (int j = 0; j < l; j++) {
					grid[i][j] = ch[j];
					if (ch[j] == 'C') {
						sx = i;
						sy = j;
					}
					if (ch[j] == 'W') {
						ex = i;
						ey = j;
					}
				}
			}
			visited = new boolean [w][l];
			Queue<Point> q = new LinkedList<Point>();
			q.offer(new Point(sx, sy, 0));
			visited[sx][sy] = true;
			boolean done = false;
			while (!q.isEmpty()) {
				Point curr = q.poll();
				if (curr.x == ex && curr.y == ey) {
					done = true;
					System.out.println(curr.steps >= 60 ? "#notworth" : curr.steps);
					break;
				}

				for (int i = 0; i < 4; i++) {
					int currx = curr.x + movex[i];
					int curry = curr.y + movey[i];
				if (currx < 0 || curry < 0 || currx >= w || curry >= l || visited[currx][curry] || grid[currx][curry] == 'X')
						continue;
					q.offer(new Point(currx, curry, curr.steps + 1));
					visited[currx][curry] = true;
				}
			}
			if (!done) 
				System.out.println("#notworth");
		}
	}

	static class Point {
		int x, y, steps;

		Point (int x, int y, int steps) {
			this.x = x;
			this.y = y;
			this.steps = steps;
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
