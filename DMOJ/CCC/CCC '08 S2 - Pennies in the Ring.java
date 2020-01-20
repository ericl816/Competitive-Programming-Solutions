import java.io.*;
public class PenniesInTheRug {

    
    public static void main(String[] args) throws IOException {
        
       BufferedReader f = new BufferedReader (new InputStreamReader (System.in));
        int radius, pennies;
	double r2;
	

	radius = Integer.parseInt(f.readLine());
	while (radius != 0)
	{
	    pennies = 0;
	    r2 = (double) (radius) * radius;
	    for (int x = 1 ; x <= radius ; x++)
		pennies += (int) Math.sqrt (r2 - (double) x * x) + 1;
	    pennies = 4 * pennies + 1;
	  System.out.println (pennies);
	    radius = Integer.parseInt(f.readLine());
           
	}
        }
       
    }