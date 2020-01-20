import java.util.*;
public class CipherText {

    
    public static void main(String[] args) {
        Scanner f = new Scanner(System.in);
	String plain, c1, c2;
	String decode = "...........................";
	String characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	int x;
	int count, dot;

	plain = f.nextLine();
	c1 = f.nextLine();
	c2 = f.nextLine ();
	
	// fill decode
	for (int i = 0 ; i < c1.length () ; i++)
	{
	    x = characters.indexOf (c1.charAt (i));
	    decode = decode.substring (0, x) + plain.charAt (i) + decode.substring (x + 1);
	}
	// if only one '.' in decode, its value can be inferred
	count = 0;
	for (int i = 0 ; i < decode.length () ; i++)
	    if (decode.charAt (i) == '.')
		count++;
	if (count == 1)
	{
	    dot = decode.indexOf ('.');
	    for (int i = 0 ; i < 27 ; i++)
	    {
		x = decode.indexOf (characters.charAt (i));
		if (x == -1)
		    decode = decode.substring (0, dot) + characters.charAt (i) + decode.substring (dot + 1);
	    }
	}
	
	// decrypt the ciphertext
	for (int i = 0 ; i < c2.length () ; i++)
	{
	    x = characters.indexOf (c2.charAt (i));
	    System.out.print (decode.charAt (x));
	}
    }
}