import java.util.*;

public class CCC2007S1FederalVotingAge
{


    public static void main (String[] args) 
    {
	Scanner f = new Scanner(System.in);
	int n, y, m, d;

	n = f.nextInt();
	for (int i = 0 ; i < n ; i++)
	{
	    y = f.nextInt();
	    m = f.nextInt();
	    d = f.nextInt();
	    if ((y < 1989) ||
		    (y == 1989 && m < 2) ||
		    (y == 1989 && m == 2 && d <= 27))
		System.out.println ("Yes");
	    else
		System.out.println ("No");
	}
    }
}