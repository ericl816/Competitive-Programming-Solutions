import java.io.*;

public class ISBN {

    
    public static void main(String[] args) throws IOException{ 
       
       BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
       
       int a = Integer.parseInt(in.readLine());
       int b = Integer.parseInt(in.readLine());
       int c = Integer.parseInt(in.readLine());
       
       
       System.out.println("The 1-3-sum is " + (91+a+c+b*3));
              
    }
  }