import java.io.*;
import java.util.*;
public class CCC97DynamicDictionaryCoding {
  public static int N, idx;
  public static String [] arr;
  public static HashMap<String, Integer> hm;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		N = Integer.parseInt(in.nextLine());
		for(int i=0; i<N; i++)	{
		  hm = new HashMap<String, Integer>();
			idx = 1;
			while(1 == 1) {
				arr = in.nextLine().split(" ");
				if (arr[0].isEmpty()) break;
				else {
				for(String word : arr)
			        if(hm.containsKey(word)) System.out.print(hm.get(word) + " ");
					else {
						System.out.print(word + " ");
						hm.put(word, idx++);
					}
				System.out.println();
			  }
		      }
		}
	}
}
