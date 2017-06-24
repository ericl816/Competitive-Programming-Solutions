import java.io.*;
import java.util.*;

public class DMOPC14SurpriseTeleport {

    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;

    public static int R, C, T, sx, sy, ex, ey, ans = 0;
    public static int [][] dist;
    public static char [][] grid;
    public static Point [] point;
        
	public static void main (String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new OutputStreamWriter(System.out));
		R = readInt();
		C = readInt();
		sx = readInt();
		sy = readInt();
		ex = readInt();
		ey = readInt();
                dist = new int [R][C];
                grid = new char[R][C];
		for (int i=0; i<R; i++) grid[i] = next().toCharArray();
		T = readInt();
                point = new Point [T];
		for (int i=0; i<T; i++) point[i] = new Point(readInt(), readInt());
		for (int i=0; i<R; i++)
			for (int j=0; j<C; j++)
				dist[i][j] = 1 << 30;
		dist[sx][sy] = 0;
		Queue<Point> q = new LinkedList<Point>();
		q.offer(new Point(sx, sy));
		while (!q.isEmpty()) {
			Point curr = q.poll();
			for (int i=-1; i<=1; i++) {
                for (int j=-1; j<=1; j++) {
                   if (Math.abs(i) + Math.abs(j) == 1) {
                   int currx = curr.x + i;
                   int curry = curr.y + j;
                   if (currx < 0 || currx >= R || curry < 0 || curry >= C || grid[currx][curry] == 'X' || dist[curr.x][curr.y] + 1 >= dist[currx][curry])
                        continue;
                            dist[currx][curry] = dist[curr.x][curr.y] + 1;
                            q.offer(new Point(currx, curry));
                                }
                            }
                        }
		}
		for (int i=0; i<T; i++) ans = Math.max(ans, dist[ex][ey] - dist[point[i].x][point[i].y]);
		System.out.println(ans);
	}

	static class Point {
		int x, y;
		Point (int a, int b) {
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
