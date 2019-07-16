import java.io.*;
import java.util.*;

public class checker {

private static checker o = new checker();

public class Reader {
	private final int BUFFER_SIZE = 1 << 16;
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
  
  public static int M, N, op, R, C, X, R1, C1, R2, C2, ans;
  public static int [][] BIT;

  public static void main (String[] args) throws IOException {
    Reader r = o.new Reader();
    M = r.nextInt();
    N = r.nextInt();
    BIT = new int [M + 2][N + 2];
    op = r.nextInt();
    while (op != 0) {
      if (op == 1) {
         R = r.nextInt();
         C = r.nextInt();
         X = r.nextInt();
        if (checkColour(R, C)) X *= -1;
        Update(R, C, (X - FreqTo1(R, C)));
      } 
      else if (op == 2) {
         R1 = r.nextInt() - 1;
         C1 = r.nextInt() - 1;
         R2 = r.nextInt();
         C2 = r.nextInt();
         ans = FreqTo2(R1, C1, R2, C2);
        if (checkColour(R1, C1)) ans *= -1;
        System.out.println(ans);
      }
      op = r.nextInt();
    }
  }

  public static boolean checkColour (int x, int y) {
	      return ((x + y) & 1) == 1 ? true : false;
	}
	    
  public static void Update (int x, int y, int val) {
    int idxy = y;
    for (; x <= M; x += x & -x) {
      y = idxy;
      for (; y <= N; y += y & -y) {
        BIT[x][y] += val;
      }
    }
  }

  public static int Query (int x, int y) {
    int sum = 0;
    int idxy = y;
    for (; x > 0; x -= x & -x) { 
      y = idxy;
      for (; y > 0; y -= y & -y) {
        sum += BIT[x][y];
      }
    }
    return sum;
  }
  
  public static int FreqTo1 (int x, int y) {
	       return Query(x, y) + Query(x - 1, y - 1) - Query(x - 1, y) - Query(x, y - 1);
	}

  public static int FreqTo2 (int x1, int y1, int x2, int y2) {
	       return Query(x2, y2) + Query(x1, y1) - Query(x1, y2) - Query(x2, y1);
	}
}
