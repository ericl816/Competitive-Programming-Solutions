import java.io.*;

public class Maternity {

    
    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader (new InputStreamReader (System.in));
     
	int x;
	String mother, father, baby;

	mother = f.readLine();
	father = f.readLine();
	x = Integer.parseInt(f.readLine());
	for (int i = 1 ; i <= x ; i++)
	{
	    baby = f.readLine();
	    if (possibleBaby (mother, father, baby))
		System.out.println ("Possible baby.");
	    else
		System.out.println ("Not their baby!");
	}
    }

    public static boolean possibleBaby (String m, String f, String b)
    {
	boolean okay = true;
	for (int i = 0 ; i <= 4 && okay ; i++)
	    if (b.charAt (i) >= 'A' && b.charAt (i) <= 'E')
		okay = (m.charAt (i * 2) >= 'A' && m.charAt (i * 2) <= 'E') ||
		    (m.charAt (i * 2 + 1) >= 'A' && m.charAt (i * 2 + 1) <= 'E') ||
		    (f.charAt (i * 2) >= 'A' && f.charAt (i * 2) <= 'E') ||
		    (f.charAt (i * 2 + 1) >= 'A' && f.charAt (i * 2 + 1) <= 'E');
	    else
		okay = ((m.charAt (i * 2) >= 'a' && m.charAt (i * 2) <= 'e') ||
			(m.charAt (i * 2 + 1) >= 'a' && m.charAt (i * 2 + 1) <= 'e')) &&
		    ((f.charAt (i * 2) >= 'a' && f.charAt (i * 2) <= 'e') ||
			(f.charAt (i * 2 + 1) >= 'a' && f.charAt (i * 2 + 1) <= 'e'));
	return okay;
    }
}