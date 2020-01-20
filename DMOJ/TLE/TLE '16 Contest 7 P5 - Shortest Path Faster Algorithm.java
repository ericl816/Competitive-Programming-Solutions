import java.io.*;
import java.util.*;

public class Main {
  
   static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter ps = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
        
        static int n, m, u, v, q, curdist;
        static long d, f;
        static long [] dist = new long [300];
        static boolean [] visited = new boolean [300];
        static boolean fail;
        static ArrayList<ArrayList<Edge>> al = new ArrayList<ArrayList<Edge>>();
      static PriorityQueue<Vertex> pq = new PriorityQueue<Vertex>();
        
  public static void main (String [] args) throws IOException {
    n = readInt();
    m = readInt();
    for (int i=0; i<n; i++){
      dist[i] = Long.MAX_VALUE;
      al.add(new ArrayList<Edge>());
    }
    for (int i=1; i<=m; i++){
      u = readInt() - 1;
      v = readInt() - 1;
      d = readLong();
      al.get(u).add(new Edge(u, v, d));
      al.get(v).add(new Edge(v, u, d));
    }
    q = readInt();
        for (int k=0; k<q; k++){
      f = readLong();
        SPFA();
      System.out.println(dist[k] == Long.MAX_VALUE ? "Fail" : dist[k]);
    }
  }
  
    public static void SPFA () {
      pq.offer(new Vertex(u, v, f));
    visited[0] = true;
    fail = false;
    while(!pq.isEmpty()){
      Vertex curr = pq.poll();
      for (Edge e : al.get(curr.u)){
        if (visited[curr.v])
        continue;
        visited[curr.v] = true;
         curdist = e.v + curr.v;
        if (dist[e.v] > curdist)
        dist[e.v] = Math.min(dist[e.v], curdist);
        pq.offer(new Vertex(e.u, e.v, Math.min(dist[e.v], curdist)));
      }
    }
    }
      
    public static class Edge implements Comparable <Edge>{
      int u, v;
      long d;
      
      Edge(int a, int b, long c) {
      this.u = a;
      this.v = b;
      this.d = c;
      }
      
      @Override
      public int compareTo(Edge a){
        return this.v - a.v;
      }
      
    }
    public static class Vertex{
      int u, v;
      long dur;
      
      Vertex(int a, int b, long c){
        this.u = a;
        this.v = b; 
        this.dur = c;
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