import java.io.*;
import java.util.*;

class Reader {

    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;
    private int http;

    public Reader() {
        din = new DataInputStream(System.in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public Reader(String file_name) throws IOException {
        din = new DataInputStream(new FileInputStream(file_name));
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public String readLine() throws IOException {
        byte[] buf = new byte[64]; // line length
        int cnt = 0, c;
        while ((c = read()) != -1) {
            if (c == '\n') {
                break;
            }
            buf[cnt++] = (byte) c;
        }
        return new String(buf, 0, cnt);
    }

    public int nextInt() throws IOException {
        int ret = 0;
        byte c = read();
        while (c <= ' ') {
            c = read();
        }
        boolean neg = (c == '-');
        if (neg) {
            c = read();
        }
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');

        if (neg) {
            return -ret;
        }
        return ret;
    }

    public long nextLong() throws IOException {
        long ret = 0;
        byte c = read();
        while (c <= ' ') {
            c = read();
        }
        boolean neg = (c == '-');
        if (neg) {
            c = read();
        }
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');
        if (neg) {
            return -ret;
        }
        return ret;
    }

    public double nextDouble() throws IOException {
        double ret = 0, div = 1;
        byte c = read();
        while (c <= ' ') {
            c = read();
        }
        boolean neg = (c == '-');
        if (neg) {
            c = read();
        }

        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');

        if (c == '.') {
            while ((c = read()) >= '0' && c <= '9') {
                ret += (c - '0') / (div *= 10);
            }
        }

        if (neg) {
            return -ret;
        }
        return ret;
    }

    private void fillBuffer() throws IOException {

        bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        if (bytesRead == -1) {
            buffer[0] = -1;
        }
    }

    private byte read() throws IOException {
        if (bufferPointer == bytesRead) {
            fillBuffer();
        }
        return buffer[bufferPointer++];
    }

    public void close() throws IOException {
        if (din == null) {
            return;
        }
        din.close();
    }
}

public class DMOPC14SurpriseTeleport {

        public static int R, C, T, sx, sy, ex, ey, ans = 0;
        public static int [][] dist;
        public static char [][] grid;
        public static Point [] point;
        public static Queue<Point> q = new LinkedList<Point>();
        
	public static void main (String[] args) throws IOException {
		Reader r = new Reader();
		R = r.nextInt();
		C = r.nextInt();
		sx = r.nextInt();
		sy = r.nextInt();
		ex = r.nextInt();
		ey = r.nextInt();
                dist = new int [R][C];
                grid = new char[R][C];
		for (int i=0; i<R; i++) grid[i] = r.readLine().toCharArray();
		T = r.nextInt();
                point = new Point [T];
		for (int i=0; i<T; i++) point[i] = new Point(r.nextInt(), r.nextInt());
		for (int i=0; i<R; i++)
                    for (int j=0; j<C; j++)
                        dist[i][j] = 1 << 30;
		dist[sx][sy] = 0;
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
}