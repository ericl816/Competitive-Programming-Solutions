import java.io.*;
import java.util.*;

public class PracticePursuitofKnowledge {

    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;
    
    static ArrayList<ArrayList<Integer>> al = new ArrayList<ArrayList<Integer>>();
    static int [][] dist = new int [1005][1005];
    static Queue <Integer> q = new LinkedList<Integer>();
    static int N, M, T, a, b, Q, c, d;
    
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        N = readInt();
        M = readInt();
        T = readInt();
        for (int i=0; i<N; i++) {
            al.add(new ArrayList<Integer>());
            for (int j=0; j<N; j++) {
                dist[i][j] = Integer.MAX_VALUE;
            }
        }
       
        for (int i=0; i<M; i++) {
            a = readInt() - 1;
            b = readInt() - 1;
            al.get(a).add(b);
        }
        for (int i=0; i<N; i++) {
            q.add(i);
            dist[i][i] = 0;
            while (!q.isEmpty()) {
                Integer curr = q.poll();
                    for (Integer next : al.get(curr)) {
                        int currdist = dist[i][curr] + 1;
                        if (currdist >= dist[i][next]) continue;
                        else
                            dist[i][next] = currdist;
                            q.offer(next);
            }
        }
    }
        Q = readInt();
        for (int i=0; i<Q; i++) {
            c = readInt() - 1;
            d = readInt() - 1;
            System.out.println(dist[c][d] == Integer.MAX_VALUE ? "Not enough hallways!" : T * dist[c][d]);
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
