import java.io.*;

public class DMPGBFS {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader (new InputStreamReader(System.in));
        String tokens [] = in.readLine().split(" ");
        int a = Integer.parseInt(tokens[0]); int b = Integer.parseInt(tokens[1]); int c = Integer.parseInt(tokens[2]);
        int d = Integer.parseInt(tokens[3]); int e = Integer.parseInt(tokens[4]);
        int sum = 5*a+10*b+25*c+100*d+200*e;
        System.out.println(sum);
    }
    
}