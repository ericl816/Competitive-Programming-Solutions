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

public class Main {
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
    Reader r = new Reader();
		int O=r.nextInt();
		//how many countries there are
		Vector<Integer> x = new Vector<Integer>();
		Vector<Integer> y = new Vector<Integer>();
		long[][]graph=new long[O+1][O+1];

		for (int i = 0; i < O; i++) {
			int a=r.nextInt(),b=r.nextInt();
			x.add(a);
			y.add(b);
		}	
    long[] dis = new long[O];
		Boolean p[] = new Boolean[O];
		for (int i = 0; i < O; i++)
		{
			dis[i] = Long.MAX_VALUE;
			p[i] = false;
		}
    
		int X=r.nextInt()-1;
    int src = X;		
    dis[src] = 0;
    for (int i=1; i<O; i++) {
      long minn = Long.MAX_VALUE;
      int minn_node = -1;
      for (int j=0; j<O; j++) {
        if (!p[j] && dis[j] < minn) {
            minn = dis[j];
            minn_node = j;
        }
      }
      p[minn_node] = true;
      for (int j=0; j<O; j++) {
          if (!p[j]) {
              long distance = (long) Math.pow((y.get(j) - y.get(minn_node)), 2) + (long) Math.pow((x.get(j) - x.get(minn_node)), 2);
              dis[j] = Math.min(dis[j], dis[minn_node] + distance);
          }
      }
    }
		Arrays.sort(dis);
		//		for (int i : countries) {
		//		System.out.print(i+" ");
		//	}
		//	System.out.println();
		int Q=r.nextInt();

		for (int i = 0; i < Q; i++) {
			long query=r.nextLong();
      System.out.println(number_of_indexs_smaller_than_x(dis,query));
			//for (int k2 = k+1; k2 < countries.length; k2++) {
				//if(countries[k2]<=query)ans++;else break;
			//}

			//System.out.println(ans+1);			


		}

	}
	static int number_of_indexs_smaller_than_x(long[] countries,long query){
		int l = 0;
    int r = countries.length - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (countries[mid] <= query) l = mid + 1;
        else r = mid - 1;
    }
    return l;
  }
}