import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.StringTokenizer;

public class DeathGun1 {
        static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter ps = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String [] args) throws IOException {
		
		int M = readInt(), cnt=0;
		Map<String, Integer> dic = new HashMap<String, Integer>();
		ArrayList<Integer> [] adj = new ArrayList [901];
		String [] name = new String[901];
		int [] degree = new int [901];
		for(int i=0; i<901; i++)
			adj[i] = new ArrayList<Integer>();
		for(int i=0; i<M; i++){
			String s1 = next();
                        String s2 = next();
                        
			if(!dic.containsKey(s1)) {
                            name[cnt]=s1; dic.put(s1, cnt++);
                        }
			if(!dic.containsKey(s2)) {
                            name[cnt]=s2; dic.put(s2, cnt++);
                        }
			adj[dic.get(s2)].add(dic.get(s1));
                        degree[dic.get(s1)]++;
		}
		while(true){
			boolean flag = false;
			for(int i=0; i<cnt; i++){
				if(degree[i]==0){
					flag = true;
					ps.println(name[i]);
					degree[i]--;
					for(int v: adj[i])
                                            degree[v]--;
					break;
				}
			}
			if(!flag) break;
		}
                ps.close();
	}
        static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}

	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}