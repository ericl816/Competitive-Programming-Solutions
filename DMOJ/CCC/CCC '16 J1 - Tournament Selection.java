import java.io.*;
public class ccc16j1 {
    static String a;
    static int counter1, counter2;
  
    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
        for (int i = 0; i < 6; i++) {
            a = (in.readLine());
           char ch = a.charAt(0);
           if (ch == 'W') {
            counter1++;
           }
           else if (ch == 'L') {
               counter2++;
           }
        
        }
               if (counter1 >=5) {
                    System.out.println("1");
                }
          
                else if ((counter1 >=3) && (counter1 <=4)) {
                    System.out.println("2");
                }
                else if ((counter1 >=1) && (counter1 <=2)) {
                    System.out.println("3");   
                }
                else if (counter1 == 0) {
                    System.out.println("-1");
        }
      }
    }