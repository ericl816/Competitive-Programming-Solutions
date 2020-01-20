import java.io.*;
public class From1987To2013 {
    
    public static void main(String[] args) throws IOException {
        
       
            BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
            int n = Integer.parseInt(in.readLine());
            n++;
            
            while (!hasDistinctDigits(n)) {
                n++;
            }
            System.out.println(n);
    }
            
    /* returns true if all digits in parameter integer are distinct; false otherwise */
    public static boolean hasDistinctDigits(int n) {
        String s = String.valueOf(n); // string representation of the number
        int[] numbers = new int[10]; // index position represents number, element value represents occurrence of that number
        
        for (int i = 0; i < s.length(); i++) {
            int x = Integer.parseInt(s.substring(i, i+1)); // integer at this part in the string
            numbers[x]++; // increase occurrence of this integer in the array
        }
        
        // check if any digit occurred more than once in the array
        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i] > 1) { // digit occurred more than once
                return false; // not distinct
            }
        }
        return true; // hasn't returned false yet, so the integer has distinct digits
    }
}