import java.util.*;
public class Groups {

    
    public static void main(String[] args) {
       
        Scanner f = new Scanner(System.in);
	
	int[] [] g;
	int n;
	int identity;
	boolean group, found;

	n = f.nextInt();
	group = false;
	while (n > 0)
	{
	    group = true;
	    g = new int [n + 1] [n + 1];
	    
	    for (int i = 1 ; i <= n && group ; i++)
		for (int j = 1 ; j <= n && group ; j++)
		{
		    g [i] [j] = f.nextInt();
		    if (g [i] [j] < 1 || g [i] [j] > n)
			group = false;
		}

	    identity = 0;
	    found = false;
	    for (int i = 1 ; i <= n && group && identity == 0 ; i++)
	    {
		found = true;
		int j;
		for (j = 1 ; j <= n && found ; j++)
		{
		    if (g [i] [j] != j)
			found = false;
		}
		if (found)
		{

		    identity = i;
		    for (int k = 1 ; k <= n && found ; k++)
			if (g [identity] [k] != k)
			    found = false;
		}
	    }
	    group = group && found;

	    for (int i = 1 ; i <= n && group ; i++)
	    {
		found = false;
		for (int j = 1 ; j <= n && !found ; j++)
		    if (g [i] [j] == identity && g [j] [i] == identity)
			found = true;
		group = group && found;
	    }

	    for (int i = 1 ; i <= n && group ; i++)
		for (int j = 1 ; j <= n && group ; j++)
		    for (int k = 1 ; k <= n && group ; k++)
			if (g [g [i] [j]] [k] != g [i] [g [j] [k]])
			    group = false;

	    if (group)
		System.out.println ("yes");
	    else
		System.out.println ("no");
	    n = f.nextInt ();
	}
    }
}