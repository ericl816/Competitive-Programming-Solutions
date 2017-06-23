import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class GiantAnts {
        static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer st;

        static int a, b, c, d, e, ants, curr;
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new OutputStreamWriter(System.out));
		
	     a = readInt();
             b = readInt();
         
		ArrayList<ArrayList<Integer>> al = new ArrayList<ArrayList<Integer>>(a);
		for(int i=0; i < a; i++) 
			al.add(new ArrayList<Integer>());
		for(int i=0; i < b; i++) {
			 c = readInt() - 1;
                         d = readInt() - 1;
			al.get(c).add(d);
			al.get(d).add(c);
		}
		 e = readInt();

		int[][] ant = new int[e][a];
                
		for(int i=0; i<e; i++) {
			 ants = readInt()-1;

			for(int j=0; j < a; j++)
				ant[i][j] = Integer.MAX_VALUE;

			Queue<Integer> adj = new LinkedList<Integer>();
			adj.offer(ants);
			ant[i][ants] = 0;

			while(!adj.isEmpty()) {
				 curr = adj.poll();

				for(int next : al.get(curr))
					if(ant[i][next] == Integer.MAX_VALUE) {
						adj.offer(next);
						ant[i][next] = ant[i][curr] + 1;
					}
			}
		}

		int[] dist = new int[a];
		for(int i=0; i < a; i++)
			dist[i] = Integer.MAX_VALUE;

		Queue<Integer> adj = new LinkedList<Integer>();
		adj.offer(0);
		dist[0] = 0;

		while(!adj.isEmpty()) {
			int curr = adj.poll();

			for(int next : al.get(curr))
				if(dist[next] == Integer.MAX_VALUE) {
					boolean flag = true;
					for(int i = 0; flag && i < e; i++)
						flag = (dist[curr] + 1) < ant[i][next] * 4;

					if(flag) {
						adj.offer(next);
						dist[next] = dist[curr]+1;
					}
				}
		}

		if(dist[a-1] == Integer.MAX_VALUE)
			out.println("sacrifice bobhob314");
		else
			out.println(dist[a-1]);
                out.close();
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
