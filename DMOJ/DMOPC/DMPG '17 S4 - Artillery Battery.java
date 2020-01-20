import java.io.*;
import java.util.*;

public class DMPG17ArtilleryBattery {

    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;

    static char ch [] = new char[1001];
    static String s;
    static char [][] grid = new char [10][9];
    static int ex, ey, sx, sy, cnt = 0, moves = 0;
    static int [] movex = new int [] {0, 0, -1, 1};
    static int [] movey = new int [] {-1, 1, 0, 0};
    static boolean good;
    static boolean [][] visited = new boolean [1001][1001];
    static Queue<Point> q = new LinkedList<Point>();
            
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));  
        out = new PrintWriter(new OutputStreamWriter(System.out));
        for (int i=0; i<10; i++) {
                s = readLine();
           for (int j=0; j<9; j++) {
               ch [i] = s.charAt(j);
               grid[i][j] = ch[i];
               if (ch[i] == 'C') {
               sx = i; 
               sy = j;
               }
               if (ch[i] == 'E') {
                   ex = i; 
                   ey = j;
               }
            }
        }
        good = false;
        visited[sx][sy] = true; 
        q.add(new Point(sx, sy));
        while(!q.isEmpty()) {
            Point curr = q.poll();
            for (int i=0; i<4; i++) {
            int currx = curr.x + movex[i];
            int curry = curr.y + movey[i];
            if (currx < 0 || curry < 0 || currx >= 9 || curry >= 10 || visited[currx][curry]) 
                continue;
            q.offer(new Point(currx, curry)); 
            moves++;
            visited[currx][curry] = true;
            }
            if (curr.x == ex && curr.y == ey) {
               good = true;
                cnt++;
               if (good) System.out.println(cnt + " " + moves);
            }
        }
        if (!good) System.out.println("0, 0");
    }
    
    static class Point {
        int x, y;
        
        Point(int a, int b) {
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