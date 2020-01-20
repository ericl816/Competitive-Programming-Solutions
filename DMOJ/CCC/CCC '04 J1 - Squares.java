import java.util.Scanner;



public class Squares {

    public static void main(String[] args) {
        
       Scanner in = new Scanner(System.in);
       int tiles = in.nextInt();
       double n = Math.sqrt(tiles);
       if (n<tiles){
           n=n-0.5;
           
       }
       
       System.out.println ("The largest square has side length " + (Math.round(n)) + ".");
      }
}