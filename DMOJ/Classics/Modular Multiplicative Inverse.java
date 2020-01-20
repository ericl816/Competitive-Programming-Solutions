import java.util.*;
import java.math.*;
public class ModularInverse {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger a = in.nextBigInteger();
        BigInteger b = in.nextBigInteger();
        BigInteger c = a.modInverse(b);
        System.out.println(c);
        
        
        
    }
    
}