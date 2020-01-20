import java.io.*;
public class FrenchHomewok {
    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
        String s = in.readLine();
        String a = in.readLine();
        
        if (a.endsWith("s")) {
            System.out.println(s + "-tu les " + a + " ?");
        }
        else if (a.endsWith("e")) {
            System.out.println(s + "-tu la " + a + " ?");
        }
        else {
            System.out.println(s + "-tu le " + a + " ?");
        }
        
    }
    
}