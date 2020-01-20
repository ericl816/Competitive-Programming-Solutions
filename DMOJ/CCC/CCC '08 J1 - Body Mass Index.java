import java.util.Scanner;

public class Eric_Liu_C5_HW {

    public static void main(String[] args) {
       Scanner in = new Scanner(System.in);
       double weight = in.nextDouble();
       double height = in.nextDouble();
       double calc = weight/(height*height); 
       if(calc <18.5) {
           System.out.println("Underweight");
       }
       else if((calc >=18.5) && (calc <=25.0)) {
           System.out.println("Normal weight");
       }
       else if (calc >25.0){
           System.out.println("Overweight");
       }
     }
}