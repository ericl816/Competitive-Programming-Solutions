import java.io.*;
public class DonTPassmetheball {

    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
        int n = Integer.parseInt(in.readLine()) - 1;
        System.out.println ((n*(n-1)*(n-2))/6);
    }
    
}