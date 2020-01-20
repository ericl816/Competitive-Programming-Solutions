import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Main{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] t;
		t=br.readLine().split(" ");
		if(t.length!=1)
	    	System.out.println("MOO");
	    int n=Integer.parseInt(t[0]);
	    long[] v=new long[n+1];
	    long[] w=new long[n+1];
	    long[] pr=new long[n+1];
	    long[] dp=new long[n+1];
	    for(int i=1;i<=n;i++){
	        t=br.readLine().split(" ");
	        if(t.length!=2)
	            System.out.println("MOO");
	        v[i]=Integer.parseInt(t[0]);
	        w[i]=Integer.parseInt(t[1]);
	        pr[i]=pr[i-1]+Math.abs(v[i]-w[i-1]);
	    }
	    for(int i=1;i<=n;i++){
	        dp[i]=1000000000000000000L;
	        for(int j=1;j<=i;j++){
	            dp[i]=Math.min(dp[i], dp[j-1]+pr[i]-pr[j]+Math.abs(v[j]-w[i]));
	        }
	    }
	    System.out.println(dp[n]);
	}
}