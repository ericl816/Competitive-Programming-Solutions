import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner c = new Scanner(System.in);
        int k, i;
        char[] letter = new char[31];
        String[] code = new String[31];
        String binary, ans = "";
        k = c.nextInt();
        for (i=0; i<k; i++) {
            char a = c.next().charAt(0);
            letter[i] = a;
            code[i] = c.next();
    	}
    	binary = c.next();
    	while (binary.length() > 0) {
    	    i = 0;
    	    while (!binary.startsWith(code[i])) i++;
    		ans += letter[i];
    	    binary = binary.substring(code[i].length());
    	}
    	System.out.println(ans);
    }
}