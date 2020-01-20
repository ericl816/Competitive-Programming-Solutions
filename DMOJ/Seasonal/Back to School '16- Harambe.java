import java.io.*;
public class Harambe {

    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader (new InputStreamReader (System.in)); 
        String s = (in.readLine());
        char ch;
        int counter1 = 0;
        int counter2 = 0;
        for (int i = 0; i < s.length(); i++){
            ch = s.charAt(i);
            if (Character.isLowerCase(ch)) {
                counter1++;
            }
            else if(Character.isUpperCase(ch)) {
                counter2++;
            }
    }
        if (counter1 > counter2) {
            System.out.println(s.toLowerCase());
        }
        else if (counter1 < counter2) {
            System.out.println(s.toUpperCase());
        }
        else {
            System.out.println(s);
        } 
            
    }
    
}