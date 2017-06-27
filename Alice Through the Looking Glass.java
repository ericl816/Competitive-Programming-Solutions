import java.io.*;
import java.util.*;

public class CCC11AliceThroughTheLookingGlass {

	public static void main(String[] args) {
		Scanner scan = new Scanner (System.in);
		int n = scan.nextInt();
		
		for(int i=0; i<n; i++){
			int m = scan.nextInt();
			int x = scan.nextInt();
			int y = scan.nextInt();
			

			if(y<AtSquare(m,x)){
				System.out.println("crystal");
			}
			else{
				System.out.println("empty");
			}
		}
	}
	public static int AtSquare (int mag, int x){
		if(mag>0){
			int exp = power(5, mag-1);
			int pos = x/exp;
			if(pos==0 || pos==4){
				return 0;
			}
			else if(pos==1 || pos==3){
				return 1 * exp + AtSquare(mag - 1, x % exp);
			}
			else if(pos==2){
				return 2 * exp + AtSquare(mag - 1, x % exp);
			}
		}
		return 0;
	}
	public static int power(int a, int b){
		int total = a;
		if(b == 0 || a==1) return 1;
		if(b == 1) return a;
		for(int i=1; i<b; i++){
			total = total*a;
		}
		return total;
	}
}
