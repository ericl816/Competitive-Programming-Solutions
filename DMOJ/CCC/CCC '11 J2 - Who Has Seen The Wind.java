import java.io.*;

public class WhoHasSeenTheWind {

    
    public static void main(String[] args) throws IOException {
       BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
       int h = Integer.parseInt(in.readLine());
       int M = Integer.parseInt(in.readLine());
       int t = 1;
       int A = -6*t*t*t*t + h*t*t*t + 2*t*t + t;
       
       while (t<M && A>0) {
           t++;
           A = -6*t*t*t*t + h*t*t*t + 2*t*t + t;
       }
       if (A>0) {
           System.out.println("The balloon does not touch ground in the given time.");
       }
       else {
           System.out.println("The balloon first touches ground at hour: \n" + t);
    }
    }
}