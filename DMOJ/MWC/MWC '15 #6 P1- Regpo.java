import java.io.*;
public class Regpo {

    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
        float n = Integer.parseInt(in.readLine());
        float a;
        a = 360/n;
        System.out.println(a);
    }
    
}