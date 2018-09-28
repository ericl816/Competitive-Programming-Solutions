import java.io.*;
import java.util.*;

public class DMOPC14SelectiveCutting {

    public static BufferedReader br;
    public static PrintWriter out; 
    public static StringTokenizer st;
    
    public static int N, Q;
    public static Tree tree [];
    public static Queries arr [];
    public static long mass [] = new long [100005];
    public static long BIT [] = new long [100005];
        
    public static void main(String[] args) throws IOException {
       br = new BufferedReader(new InputStreamReader(System.in));
       out = new PrintWriter(new OutputStreamWriter(System.out));
       N = readInt();
       tree = new Tree [N];
       for (int i=0; i<N; i++) tree[i] = new Tree(readInt(), i + 1);
       Arrays.sort(tree);
       Q = readInt();
       arr = new Queries [Q];
       for (int i=0; i<Q; i++) arr[i] = new Queries(readInt(), readInt(), readInt(), i);
       Arrays.sort(arr);
       int idx = 0;
       for (int i=0; i<Q; i++) {
           while (idx < N && tree[idx].mass >= arr[i].mass) {
           update(tree[idx].idx, tree[idx].mass);
           idx++; 
        }
        mass[arr[i].idx] = query(arr[i].b + 1) - query(arr[i].a);
       }
       for (int i=0; i<Q; i++) System.out.println(mass[i]);
    }
    
    public static void update (int idx, int n) {
        for (; idx <= 100000; idx += idx &- idx)
            BIT[idx] += n;
    }
    
    public static long query (int idx) {
        long ans = 0;
        for (; idx > 0; idx -= idx &- idx)
            ans += BIT[idx];
        return ans;
    }
    
    public static class Queries implements Comparable <Queries> {
        int a, b, mass, idx;
        
        Queries(int a, int b, int c, int d){
            this.a = a;
            this.b = b;
            this.mass = c;
            this.idx = d;
        }
        @Override 
        public int compareTo (Queries e) {
            return e.mass - mass;
        }
    }
    
    public static class Tree implements Comparable <Tree> {
        int mass, idx;
        
        Tree(int a, int b) {
            this.mass = a;
            this.idx = b;
        }
        @Override
        public int compareTo (Tree e) {
            return e.mass - mass;
        }
    }

    public static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	public static long readLong () throws IOException {
		return Long.parseLong(next());
	}

	public static int readInt () throws IOException {
		return Integer.parseInt(next());
	}

	public static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}

	public static char readCharacter () throws IOException {
		return next().charAt(0);
	}

	public static String readLine () throws IOException {
		return br.readLine().trim();
	}
}
