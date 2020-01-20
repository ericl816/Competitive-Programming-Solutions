import java.util.Scanner;

public class TinCanTelephoneVector {

   
    public static void main(String[] args) {
        
       Scanner f = new Scanner(System.in);
       
       
	Vector r, j, c, w, l, csj;
	int n, corners, touching;
	boolean outside, collision;

	r = new Vector (f.nextDouble (), f.nextDouble ());
	j = new Vector (f.nextDouble (), f.nextDouble ());

	n = f.nextInt ();
	touching = 0;
	for (int i = 0 ; i < n ; i++)
	{
	    outside = true;
	    collision = false;
	    corners = f.nextInt ();
	    l = new Vector ();
	    for (int k = 0 ; k < corners ; k++)
	    {
		c = new Vector (f.nextDouble (), f.nextDouble ());
		csj = c.subtract (j);
		w = csj.subtract (csj.projection (r.subtract (j)));

		// is the projection of c onto the line rj, BETWEEN r and j?
		// if yes, its inside (ie not outside)
		if (r.subtract (j).dot (csj) > 0 && j.subtract (r).dot (c.subtract (r)) > 0)
		    outside = false;

		// w is the vector perpendicular FROM the rj line to c
		// if its magnitude is zero its ON the line
		// or if the old w (l) and w form an obtuse angle that building's
		// side has crossed the rj line.
		if (w.magnitude () < 0.001 || w.dot (l) < 0)
		    collision = true;
		l = w;
	    }

	    // if any point was inside and there was any collision at all
	    // the building interferred with the tin can telephone
	    if (!outside && collision)
		touching++;
	}
	System.out.println (touching);
    }
}

class Vector
{
    protected double x, y;

    public Vector ()
    {
	x = 0;
	y = 0;
    }

    public Vector (double x, double y)
    {
	this.x = x;
	this.y = y;
    }

    public String toString ()
    {
	return "(" + x + "," + y + ")";
    }

    public Vector add (Vector a)
    {
	return new Vector (x + a.x, y + a.y);
    }

    public Vector subtract (Vector a)
    {
	return new Vector (x - a.x, y - a.y);
    }

    public Vector multiply (double a)
    {
	return new Vector (a * x, a * y);
    }

    public double magnitude ()
    {
	return Math.sqrt (x * x + y * y);
    }

    public double dot (Vector a)
    {
	return x * a.x + y * a.y;
    }

    public Vector projection (Vector a)
    {
	return a.multiply (dot (a) / (a.magnitude () * a.magnitude ()));
    }
}