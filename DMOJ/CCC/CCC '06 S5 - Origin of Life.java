import java.io.*;
import java.util.*;

public class CCC2006S4 {

   
    static int m, n, a, b, c, size;
    static Queue[] x;
    static byte[] [] life1, life2;

    public static void main (String[] args) throws IOException
    {
	
        BufferedReader f = new BufferedReader (new InputStreamReader (System.in));
	    String s;
        StringTokenizer tk = new StringTokenizer(f.readLine());


	int original;
	
	m = Integer.parseInt(tk.nextToken());
	n = Integer.parseInt(tk.nextToken());
	a = Integer.parseInt(tk.nextToken());
	b = Integer.parseInt(tk.nextToken());
	c = Integer.parseInt(tk.nextToken());
	
	life1 = new byte [m + 2] [n + 2];
	life2 = new byte [m + 2] [n + 2];
	size = (int) Math.pow (2, m * n);
	x = new Queue [size];
	for (int i = 0 ; i < size ; i++)
	    x [i] = new Queue ();

	for (int i = 0 ; i < m + 2 ; i++)
	    for (int j = 0 ; j < n + 2 ; j++)
	    {
		life1 [i] [j] = 0;
		life2 [i] [j] = 0;
	    }
	for (int i = 1 ; i <= m ; i++)
	{
	    s = f.readLine();
	    for (int j = 1 ; j <= n ; j++)
		if (s.charAt (j - 1) == '.')
		    life2 [i] [j] = 0;
		else
		    life2 [i] [j] = 1;
	}
	original = toInt ();
	fillx ();
	System.out.println ("" + breadthOrderSearchofX (original));
    }

    public static void fillx ()
    {
	for (int i = 0 ; i < size ; i++)
	{
	    to2D (i);
	    x [nextGen ()].add (i);
	}

    }

    public static int nextGen ()
    {
	boolean ok = true;
	int up, down, left, right, sum, value;
	for (int i = 1 ; i <= m ; i++)
	    for (int j = 1 ; j <= n ; j++)
	    {
		up = i - 1;
		down = i + 1;
		left = j - 1;
		right = j + 1;
		sum = life1 [up] [left] + life1 [up] [j] + life1 [up] [right] +
		    life1 [i] [left] + life1 [i] [right] +
		    life1 [down] [left] + life1 [down] [j] + life1 [down] [right];
		if (life1 [i] [j] == 1)
		    if (sum < a || sum > b)
			life2 [i] [j] = 0;
		    else
			life2 [i] [j] = 1;
		else
		    if (sum > c)
			life2 [i] [j] = 1;
		    else
			life2 [i] [j] = 0;
	    }
	return toInt ();
    }

    public static int toInt ()
    {
	int out = 0;
	int power = 1;
	for (int i = 1 ; i <= m ; i++)
	    for (int j = 1 ; j <= n ; j++)
	    {
		out += life2 [i] [j] * power;
		power *= 2;
	    }
	return out;
    }

    public static void to2D (int in)
    {
	for (int i = 1 ; i <= m ; i++)
	    for (int j = 1 ; j <= n ; j++)
	    {
		life1 [i] [j] = (byte) (in % 2);
		in = in / 2;
	    }
    }
    
    public static int breadthOrderSearchofX (int start)
    {
	Queue q1 = new Queue ();
	Queue q2 = new Queue ();
	boolean keepgoing = true;
	int count = 0;
	int k;
	int h;
	q1.add (start);
	while (keepgoing && count < 50)
	{
	    while (!q1.empty () && keepgoing)
	    {
		h = q1.remove ();
		if (x [h].empty ())
		    keepgoing = false;
		else
		{
		    x [h].reset ();
		    while (!x [h].emptied ())
		    {
			k = x [h].getNext ();
			q2.add (k);
		    }
		}
	    }
	    if (keepgoing)
	    {
		q1 = q2;
		q2 = new Queue ();
		count++;
	    }
	}
	if (count < 50)
	    return count;
	else
	    return -1;
    }
}

class Node
{
    public int data;
    Node next;

    public Node (int x)
    {
	data = x;
	next = null;
    }
}

class Queue
{
    Node front, back, ptr;

    public Queue ()
    {
	front = null;
	ptr = null;
	back = null;
    }


    public boolean empty ()
    {
	return front == null;
    }


    public boolean emptied ()
    {
	return ptr == null;
    }



    public void add (int x)
    {
	Node nn = new Node (x);
	if (empty ())
	{
	    front = nn;
	    ptr = nn;
	}
	else
	    back.next = nn;
	back = nn;
    }


    public int remove ()
    {
	if (empty ())
	    return -1;
	else
	{
	    int hold = front.data;
	    front = front.next;
	    ptr = front;
	    return hold;
	}
    }


    public int getNext ()
    {
	if (emptied ())
	    return -1;
	else
	{
	    int hold = ptr.data;
	    ptr = ptr.next;
	    return hold;
	}
    }


    public void reset ()
    {
	ptr = front;
    }
}