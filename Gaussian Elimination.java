import java.io.*;

public class TLE16GaussianElimination {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
        int n = Integer.parseInt(in.readLine());
        int m = Integer.parseInt(in.readLine());
       
		if (GaussianElim(n, m)){
                    System.out.println("First");
                }
                else 
                    System.out.println("Second");

      
    }
   
    public static boolean GaussianElim(int a, int b){
        if(Math.min(a, b) == 1 || ((a % 2 == 0) ^ (b % 2 == 0))){
			return true;
        }
        else 
            return false;
    }       
}
