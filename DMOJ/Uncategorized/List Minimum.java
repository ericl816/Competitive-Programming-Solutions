import java.io.*;
import java.util.*;
public class ListMinimum {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
        Integer a = Integer.parseInt(in.readLine());
        Integer iarr[] = new Integer [a];
        for (int i=0; i<a; i++) {
           iarr [i] = Integer.parseInt(in.readLine());;
        }
         Arrays.sort(iarr);
            for (int j = 0; j < iarr.length; j++){
                System.out.println(iarr[j]);
            }
    }
    
}