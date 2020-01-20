import java.util.*;
public class VasileHaircut {

static int n, a, b, c, d, e;    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        for (int i = 0; i < n; i++) {
            a = in.nextInt();
            System.out.print(" ");
            b = in.nextInt();
            System.out.print(" ");
            c = in.nextInt();
            System.out.print(" ");
            d = in.nextInt();
            e = Math.abs(a-d);
            if ((e >= b) && (e <= c)) {
            System.out.println("Yes");
            }
            else {
                System.out.println("No");
        }
        }
        
       
    }
    
}