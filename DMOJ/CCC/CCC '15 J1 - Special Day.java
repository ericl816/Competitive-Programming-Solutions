import java.util.Scanner;
public class CCCOlympiadProblemJ1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        
        int x = scan.nextInt();
        int y = scan.nextInt();
        
        if(x<2 || (x==2 && y<18)){
            System.out.println("Before");
        }
        
        if(x==2 && y==18){
            System.out.println("Special");
        }
        
        if(x>2 || (x==2 && y>18)){
            System.out.println("After");
        }
        
        // End of code
    }
    
}