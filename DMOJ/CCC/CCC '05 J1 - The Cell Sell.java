import java.text.DecimalFormat;
import java.util.*;
public class JavaApplication117 {

    static int d, e, w;
    static double PlanA, PlanB;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        DecimalFormat formatter = new DecimalFormat("#0.00");
     d = in.nextInt();
     e = in.nextInt();
     w = in.nextInt();
    
     if (d >100) {
         PlanA = (((d-100)*0.25) + (e * 0.15) + (w * 0.2)); 
     }
     else {
         PlanA = (e * 0.15) + (w * 0.2);
     }
     if (d>250) {
         PlanB= (((d-250) * 0.45)+(e * 0.35)+(w * 0.25));
     }
     else {
         PlanB = ((e * 0.35)+(w * 0.25));
     }
     
         
     System.out.println("Plan A costs " + formatter.format(PlanA));
     System.out.println("Plan B costs " + formatter.format(PlanB));
     if (Math.abs(PlanA-PlanB)<0.00000005) {
         System.out.println("Plan A and B are the same price.");
     }
     else if (PlanA > PlanB) {
         System.out.println("Plan B is cheapest.");
     }
     else {
        System.out.println("Plan A is cheapest.");
    }
    
    }
    
}