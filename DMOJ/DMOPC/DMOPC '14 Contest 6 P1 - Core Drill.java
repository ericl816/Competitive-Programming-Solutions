import java.io.*;

public class Drill {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
        int r = Integer.parseInt(in.readLine());
        int h = Integer.parseInt(in.readLine());
        double v = ((3.14159265358979323846264338327950288419716939937510*r*r*h)/3);
        System.out.println(String.format( "%.2f", v));
    }
    
}