import java.io.*;
import java.util.*;

public class DMOPC16MigrantMascot {

    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;
        
    static int n, m, a, b, p;
    static int [] dist;
    static ArrayList<ArrayList<Edge>> al = new ArrayList<ArrayList<Edge>>(n);
    static Queue<Point> q = new LinkedList<Point>();
    
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));
        
        n = readInt();
        m = readInt();
        dist = new int [n];
            
        for (int j=0; j<n; j++){
            dist[j] = 0;
            al.add(new ArrayList<Edge>());
        }
        
        for (int i=0; i<m; i++){
            a = readInt() - 1;
            b = readInt() - 1;
            p = readInt();
            al.get(a).add(new Edge(a, b, p));
            al.get(b).add(new Edge(b, a, p));
        }
   
        q.offer(new Point(0, 1<< 30));
        
        while(!q.isEmpty()){
            Point curr = q.poll();
            for (Edge e : al.get(curr.a)){
                if (dist[e.b] < Math.min(curr.b, e.p)){
                    dist[e.b] = Math.min(curr.b, e.p);
                    q.offer(new Point(e.b, Math.min(curr.b, e.p)));
                }
            }
        }
        dist[0] = 0;
        for (int i=0; i<n; i++)
            System.out.println(dist[i]);
    }
    
    public static class Point {
        int a, b;
        Point(int a, int b){
            this.a = a ;
            this.b = b;
        }
    }
    
    public static class Edge implements Comparable <Edge>{
        int a, b, p;
        Edge(int a, int b, int c){
            this.a = a;
            this.b = b;
            this.p = c;
        }
        
        @Override
        public int compareTo(Edge w){
            return w.p - p;
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