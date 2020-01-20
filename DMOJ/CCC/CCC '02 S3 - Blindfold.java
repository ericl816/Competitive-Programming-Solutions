import java.io.*;
public class BlindFold {

    static char [] [] grid;
    static int r, c, n;
    static char [] m;

    public static void main(String[] args) throws IOException {
        BufferedReader fi = new BufferedReader (new InputStreamReader (System.in));

	String line;
        
	r = Integer.parseInt(fi.readLine());
	c = Integer.parseInt(fi.readLine());
	grid = new char [r] [c];
	for (int i = 0 ; i < r ; i++)
	{
	    line = fi.readLine();
	    for (int j = 0 ; j < c ; j++)
		grid [i] [j] = line.charAt (j);
	}

	n = Integer.parseInt(fi.readLine());
	m = new char [n];
	for (int i = 0 ; i < n ; i++)
	    m [i] = (fi.readLine ()).charAt (0);

	for (int i = 0 ; i < r ; i++)
	    for (int j = 0 ; j < c ; j++)
		for (int d = 0 ; d < 360 ; d = d + 90)
		    check (i, j, d);

	for (int i = 0 ; i < r ; i++)
	{
	    for (int j = 0 ; j < c ; j++)
		System.out.print (grid [i] [j]);
	    System.out.println ();
	}
	
	
    }
    
    public static void check (int i, int j, int dir)
    {
	int pi, pj, k;
	pi = i;
	pj = j;
	k = 0;
	while (pi >= 0 && pi < r && pj >= 0 && pj < c &&
		(grid [pi] [pj] == '.' || grid [pi] [pj] == '*') &&
		k < n)
	{
	    if (m [k] == 'R')
	    {
		dir = dir - 90;
		if (dir < 0)
		    dir = 270;
	    }
	    else if (m [k] == 'L')
		dir = (dir + 90) % 360;
	    else if (m [k] == 'F')
	    {
		if (dir == 0)
		    pj = pj + 1;
		else if (dir == 180)
		    pj = pj - 1;
		else if (dir == 90)
		    pi = pi - 1;
		else
		    pi = pi + 1;
	    }
	    k++;
	}

	if (k >= n && pi >= 0 && pi < r && pj >= 0 && pj < c &&
		grid [pi] [pj] == '.')
	    grid [pi] [pj] = '*';

    }
}