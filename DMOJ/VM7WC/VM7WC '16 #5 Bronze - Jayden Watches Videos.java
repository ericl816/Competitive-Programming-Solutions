import java.io.*;
import java.util.*;
public class VMMS {

    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
        StringTokenizer st = new StringTokenizer (in.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = a*b-a;
        System.out.println(c);
    }
    
}