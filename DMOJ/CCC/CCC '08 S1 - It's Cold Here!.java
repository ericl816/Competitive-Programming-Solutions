import java.util.*;
public class ItSColdHere {
   
    public static void main(String[] args) {
        String city, coldestCity;
	int temp, coldest;
	Scanner f = new Scanner(System.in);

	city = f.next();
	coldestCity = city;
	coldest = f.nextInt();
	while (!city.equals ("Waterloo"))
	{
	    city = f.next();
	    temp = f.nextInt();
	    if (temp < coldest)
	    {
		coldestCity = city;
		coldest = temp;
	    }
	}
	System.out.println (coldestCity);
    }
}