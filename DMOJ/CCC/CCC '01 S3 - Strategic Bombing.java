import java.util.*;
import java.io.*;

public class StrategicBombing {

    
    public static void main(String[] args) throws IOException {
       
        BufferedReader fi = new BufferedReader (new InputStreamReader (System.in));
       boolean [] [] adj = new boolean [26] [26];
	String [] roads = new String [1000];
	String s;
	int a, b;
	int n, count;

	s = fi.readLine();
	n = 0;
	count = 0;
	while (!s.equals ("**"))
	{
	    roads [n++] = s;
	    s = fi.readLine();
	}
	
	for (int i = 0 ; i < n ; i++)
	{

	    for (int k = 0 ; k < 26 ; k++)
		for (int j = 0 ; j < 26 ; j++)
		{
		    if (k == j)
			adj [k] [j] = true;
		    else
			adj [k] [j] = false;
		}

	    for (int j = 0 ; j < n ; j++)
	    {
		if (j != i)
		{
		    a = roads [j].charAt (0) - 'A';
		    b = roads [j].charAt (1) - 'A';
		    adj [a] [b] = true;
		    adj [b] [a] = true;
		}
	    }

	    warshalls (adj);

	    if (!adj [0] [1])
	    {
		System.out.println (roads [i]);
		
		count++;
	    }
	}
	System.out.println ("There are " + count + " disconnecting roads.");
	
    }
    
    static public void warshalls (boolean [] [] a)
    {
	for (int y = 0 ; y < 26 ; y++)
	    for (int x = 0 ; x < 26 ; x++)
		if (a [x] [y])
		    for (int j = 0 ; j < 26 ; j++)
			if (a [y] [j])
			    a [x] [j] = true;
    }
}