import java.io.*;
public class WhichAlien {

    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
        
        int a = Integer.parseInt(in.readLine());
       
        int e = Integer.parseInt(in.readLine());
           
                if (a>=3 && e<=4) {
                    System.out.println("TroyMartian");
                }
                if (a<=6 && e>=2) {
                    System.out.println("VladSaturnian");  
                }
                if (a<=2 && e<=3) {
                    System.out.println("GraemeMercurian");   
                }
        }       
    }