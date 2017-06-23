import java.util.*;
public class LongestCommonSubsequence {

    public static void main(String[] args) {
     Scanner in = new Scanner (System.in);
      int a = in.nextInt();
      int s [] = new int [a];
      int b = in.nextInt();
      int q [] = new int [b];
      for (int i=0; i<a; i++){
      s[i] = in.nextInt();
      }
      for (int j=0; j<b; j++){
         q[j] = in.nextInt();
      }
       System.out.println(getlcs(s,q));
    }
    
    public static int getlcs(int [] a, int [] b){
	int m = a.length;
	int n = b.length;
	int[][] dp = new int[m+1][n+1];
 
	for(int i=0; i<=m; i++){
		for(int j=0; j<=n; j++){
			if(i==0 || j==0){
				dp[i][j]=0;
			}else if(a[i-1]==b[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
 
	return dp[m][n];
}
}
