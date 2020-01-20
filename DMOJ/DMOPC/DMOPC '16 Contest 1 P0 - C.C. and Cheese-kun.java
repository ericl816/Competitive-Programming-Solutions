import java.io.*;
public class Pizza {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader (new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        int a = Integer.parseInt(in.readLine());
        if (n==3 && a>=95){
            System.out.println("C.C. is absolutely satisfied with her pizza.");
        }
        else if (n==1 && a<=50){
            System.out.println("C.C. is fairly satisfied with her pizza.");
        }
        else {
            System.out.println("C.C. is very satisfied with her pizza.");
        }
                
    }
    
}