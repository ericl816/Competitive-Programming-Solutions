import java.io.*;
public class EnglishorFrench {
 
    public static void main(String[] args) throws IOException {   
        BufferedReader fi = new BufferedReader (new InputStreamReader (System.in));
        
        int n = Integer.parseInt(fi.readLine());
        int count1 = 0;
        int count2 = 0;
        for (int i =0; i<n; i++) {
            String str1 = fi.readLine();
            for (int j=0; j<str1.length();j++){
                char ch = str1.charAt(j);
                if (ch == 't' || ch == 'T'){
                    count1++;
                }
                else if (ch == 's' || ch == 'S'){
                count2++;
            }
            }
        }
         if (count1>count2){
            System.out.println("English");
        }
        else if (count2>count1){
            System.out.println("French");
        }
        else if (count1==count2){
            System.out.println("French");
        }
    }
    
}