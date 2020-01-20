import java.io.*;
public class FloorPlan {

    static int [] [] house;
    static int r, c;

    public static void main (String [] args) throws IOException 
    {
	BufferedReader fi = new BufferedReader (new InputStreamReader (System.in));
        
	String line;
	int n, k;
	int [] room;
	int count, largest;
	boolean done;
        
	n = Integer.parseInt(fi.readLine());
	r = Integer.parseInt(fi.readLine());
	c = Integer.parseInt(fi.readLine());
	house = new int [r] [c];
	for (int i = 0 ; i < r ; i++)
	{
	    line = fi.readLine ();
	    for (int j = 0 ; j < c ; j++)
		if (line.charAt (j) == 'I')
		    house [i] [j] = -1;
		else
		    house [i] [j] = 0;
	}
	
	k = 1;
	for (int i = 0 ; i < r ; i++)
	    for (int j = 0 ; j < c ; j++)
		if (house [i] [j] == 0)
		{
		    check (i, j, k);
		    k++;
		}

	room = new int [500];
	for (int i = 0 ; i < r ; i++)
	    for (int j = 0 ; j < c ; j++)
		if (house [i] [j] > 0)
		    room [house [i] [j]]++;

	count = 0;
	done = false;
	while (!done && n > 0)
	{
	    largest = 0;
	    for (int i = 0 ; i < 500 ; i++)
		if (room [i] > room [largest])
		    largest = i;
	    if (room [largest] > 0)
	    {
		if (room [largest] <= n)
		{
		    n = n - room [largest];
		    room [largest] = -1;
		    count++;
		}
		else
		    done = true;
	    }
	    else
		done = true;
	}
        if (count==1) {
            System.out.println(count + " room, " + n + " square metre(s) left over");
        }
        else {
	System.out.println (count + " rooms, " + n + " square metre(s) left over");
        }
    }
    public static void check (int i, int j, int k)
    {
	if (i >= 0 && i < r && j >= 0 && j < c && house [i] [j] == 0)
	{
	    house [i] [j] = k;
	    check (i - 1, j, k);
	    check (i + 1, j, k);
	    check (i, j + 1, k);
	    check (i, j - 1, k);
	}
    }
}