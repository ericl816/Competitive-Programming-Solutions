import java.io.*;
public class StudentCouncil {
    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
       
        int r,g,p,o,m;
        p = Integer.parseInt(in.readLine());
        g = Integer.parseInt(in.readLine());
        r = Integer.parseInt(in.readLine());
        o = Integer.parseInt(in.readLine());
        m = Integer.parseInt(in.readLine());
        int sum = 0;
        int min = Integer.MAX_VALUE;
        for (int i =0; i<=m/p; i++) {
            for (int j=0; j<=m/g; j++) {
                for (int k=0; k<=m/r; k++) {
                    for (int l = 0; l<=m/o; l++) {
                        if (i*p+j*g+k*r+l*o==m) {
                            if (min > (i+j+k+l)){
                                min = (i+j+k+l);
                            }
                            System.out.println("# of PINK is "+i + " # of GREEN is "+ j
                            + " # of RED is "+ k + " # of ORANGE is "+l);
                            sum++;
                        }
                    }
                }
            }
        }
        System.out.println("Total combinations is "+ sum + ".");
        System.out.println("Minimum number of tickets to print is "+ min + ".");
    }
}