import java.util.*;
public class Homework {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt(); 
        int M = 10000000;
        int [] pf = new int [M+1];
        for (int i=2; i<=M; i++) if (pf[i]==0)for (int j=i; j<=M; j+=i) pf[j]++;
        for (int k=1; k<=a; k++) {
            int f = in.nextInt();
            int b = in.nextInt();
            int m = in.nextInt();
            int cnt = 0;
            for (int j=f; j<=b; j++) if (pf[j] == m) cnt++;
            System.out.println("Case #"+ k + ": " + cnt);
        }
    } 
}