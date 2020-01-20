import java.util.*;
public class IconScaling {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String star = "";
        String x = "";
        String space = "";
        for (int i = 0; i < n; i++){
            star += "*";
            x += "x";
            space += " ";
        }
        for (int j = 0; j < n; j++){
            System.out.println(star+x+star);
        }
        for (int k = 0; k < n; k++){
            System.out.println(space+x+x);
        }
        for (int l = 0; l < n; l++){
            System.out.println(star+space+star);
        }
    }
    
}