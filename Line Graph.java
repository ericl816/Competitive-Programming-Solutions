import java.io.*;
import java.util.*;

public class DMOPC15LineGraph1 {

    static int [] lead;
    static int [] rank;
    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
	out = new PrintWriter(new OutputStreamWriter(System.out));
        int n = readInt();
        int k = readInt();
        int cost = 0;
        
        lead = new int [k];
        rank = new int [k];
        
        for (int i=0; i<k; i++){
            lead[i] = i;
            rank[i] = 1; 
        }
       
        ArrayList<Edge> al = new ArrayList<Edge>();
        for (int j=0; j<n-1; j++){
         al.add(new Edge(j%k, (j+1) % k, readInt()));
        }
        
        Collections.sort(al);
        for (int i=0; i<al.size() && k>1; i++){
         int a = find(al.get(i).a);
         int b = find(al.get(i).b);
        if (a!=b){
            k--;
            union(a, b);
            cost += al.get(i).cost;
        }
        }
        System.out.println(cost);
    }
    
    static class Edge implements Comparable <Edge>{
        int a;
        int b;
        int cost;
        
        Edge (int a, int b, int cost){
        this.a = a;
        this.b = b;
        this.cost = cost;
        }
        @Override
        public int compareTo(Edge e){
            return cost - e.cost;
    }
    }
            
    public static int find (int a){
      return lead[a] == a ? a : (lead[a] = find(lead[a]));
    }
    
    public static void union (int a, int b){
        int c = find(a);
        int d = find(b);
        
        if (c!=d){
            if (rank[c] > rank[d]){
                rank[c] += rank[d];
                lead[d] = c;
            }
            
            else {
                rank[d] += rank[c];
                lead[c] = d;
                /*if (rank[c] == rank[d])
                   rank[d]++;
                        */
            }
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
