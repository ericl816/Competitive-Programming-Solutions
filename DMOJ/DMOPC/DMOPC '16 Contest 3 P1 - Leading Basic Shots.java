import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class DMOPCLeadingBasicShots {

        static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter ps = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        ArrayList <String> hm = new ArrayList<String>();
        ArrayList <Long> al = new ArrayList<Long>();
        long a = readLong();
        al.add(a);
        String s = readLine();
        hm.add(s);
        long b = readLong();
       for (String q : hm){
           if (q.equals("Infront")){
               long c = al.get(0)-b;
                 System.out.println(c);
                
           }
           else if (q.equals("Behind")){
                long c = al.get(0)+b;
                System.out.println(c);
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