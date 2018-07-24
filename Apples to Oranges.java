import java.io.*;
import java.util.*;

public class DMPG15ApplestoOranges {
    
	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer st;

        static int N, M, a, b;
        static double c;
        static ArrayList <Edge>[] al = new ArrayList[501];
        static HashMap<String, Integer> hm = new HashMap<String, Integer>();
        static Queue<Integer> q = new LinkedList<Integer>();
        static double [] max = new double[501];
        
	public static void main (String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new OutputStreamWriter(System.out));
		 N = readInt();
		 M = readInt();
		for (int i = 0; i < N; i++) {
			hm.put(next(), i); 
			al[i] = new ArrayList<Edge>();
		}
		for (int i = 0; i < M; i++) {
			 a = hm.get(next());
			 b = hm.get(next());
			 c = readDouble();
			 al[a].add(new Edge (b, c));
		}
        max[hm.get("APPLES")] = 1.0;
		q.offer(hm.get("APPLES"));
		while (!q.isEmpty()) {
			Integer curr = q.poll();
			if (max[curr] > 1.01 && curr == hm.get("APPLES")) {
				System.out.println("YA");
				return;
			}
			for (Edge e : al[curr]) {
				if (max[e.dest] < max[curr] * e.cost) {
					max[e.dest] =  max[curr] * e.cost;
					q.offer(e.dest);
				}
			}
		}
		System.out.println("NAW");
	}

	static class Edge {
		int dest;
		double cost;

		Edge (int dest, double cost) {
			this.dest = dest;
			this.cost = cost;
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
