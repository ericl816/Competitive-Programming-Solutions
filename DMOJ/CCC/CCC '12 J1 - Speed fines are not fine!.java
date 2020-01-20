import java.io.*;
import java.util.*;
public class SpeedFinesAreNotFine {

    
    public static void main(String[] args) {
        try {
       BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
       int n = Integer.parseInt(in.readLine());
       int f = Integer.parseInt(in.readLine());
       int difference = f-n;
       
           if (f <=n) {
               System.out.println("Congratulations, you are within the speed limit!");
            }
           else 
               while (f > n) {
                   if ((difference >=1) && (difference <=20)) {
                    System.out.println("You are speeding and your fine is $100.");
                  }
                   else if ((difference >= 21) && (difference <=30)) {
                       System.out.println("You are speeding and your fine is $270.");
                   }
                   else if (difference >= 31) {
                       System.out.println("You are speeding and your fine is $500.");
                   }
                   break;
               }
           
       }
    
        catch (IOException e) {
            
        }
}
}