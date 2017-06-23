import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class DisjointSetTest {

        static int a;
        static int b;
        static int d;
        static int e;
        static int index = 0;
        static int [] lead;
        static int [] rank;
        static BufferedReader br;
	static PrintWriter out;
        static StringTokenizer st;
 
       public static int find(int c){
         return lead[c] == c ? c : (lead[c] = find(lead[c]));
     }
 
     public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
	out = new PrintWriter(new OutputStreamWriter(System.out));
        int a = readInt();
        int b = readInt();
        lead = new int [a];
        rank = new int [a];
        
       int [] ans1 = new int [a-1];
       
        for (int j=0; j<a; j++){
        lead[j] = j;
        rank[j] = 1;
        }
       
        for (int i=1; i<=b; i++){
            int e = readInt()-1;
            int f = readInt()-1;
              int g = find(e);
              int h = find(f);
            if (g != h){
               ans1[index++] = i;
                lead[g] = h;
        }
        }
        
        if (index == a-1)
            for (int q : ans1)
               out.println(q);
  else
            out.println("Disconnected Graph");
        out.close();
     }
     
        
		static String next () throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine().trim());
			return st.nextToken();
		}

		static int readInt () throws IOException {
			return Integer.parseInt(next());
		}
        }
