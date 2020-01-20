import java.io.*;
public class BrunoandTrig {
    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
        int a = Integer.parseInt(in.readLine());
        int b = Integer.parseInt(in.readLine());
        int c = Integer.parseInt(in.readLine());
        if (a+b>c && a+c>b && b+c>a){
            System.out.println("Huh? A triangle?");
        }
        else {
            System.out.println("Maybe I should go out to sea...");
        }
    }
}