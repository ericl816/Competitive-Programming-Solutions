import java.io.*;
public class SeedStrategy {

    static int a, b, count, count1, count2;
    static int c [];
    public static void main(String[] args) throws IOException {
        
        BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
       
        int a = Integer.parseInt(in.readLine());
        int b = Integer.parseInt(in.readLine());
        int c [] = new int [b];
        for (int i = 0; i < b; i++){
         c [i] = Integer.parseInt(in.readLine());
         
    }
        for (int j = 0; j < c.length; j++){
            if (c[j]==1){
                count++;
            }
            else if (c[j]==2){
                count1++;
            }
            else if (c[j]==3){
                count2++;
            }  
        }
         double sum = (count*0.5) + (count1) + (count2*5);
            if (sum <=a){
                System.out.println("Continue");
            }
            else {
                System.out.println("Return");
            }
    }
    
}