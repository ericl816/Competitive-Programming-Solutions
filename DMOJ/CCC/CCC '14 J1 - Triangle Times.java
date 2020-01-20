import java.io.*;

public class TriangleTimes {

    
    public static void main(String[] args) throws IOException {
        
            BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
            int a = Integer.parseInt(in.readLine());
            int b = Integer.parseInt(in.readLine());
            int c = Integer.parseInt(in.readLine());
            
           if (a + b + c != 180) {
               System.out.println("Error");
            }
           while (a + b + c == 180)  {
               if (a==b && b==c && a==c) {
                   System.out.println("Equilateral");
                    }
               else if (a==b || b==c || a==c) {
                   System.out.println("Isosceles");
                  }
               else if (a!=b || b!=c || a!=c){
                   System.out.println("Scalene");
                    } 
                   break;
          }
       }
     }