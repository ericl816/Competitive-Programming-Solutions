import java.io.*;
public class FlyingPlushies {

    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
        int n = Integer.parseInt(in.readLine());
        int m = Integer.parseInt(in.readLine());
        int count = 0;
        for (int i=0; i<m; i++) {
            int h = Integer.parseInt(in.readLine());
            if (h>=n) {
                count++;
            }
           
        }
         System.out.println(count);
    }
    
}