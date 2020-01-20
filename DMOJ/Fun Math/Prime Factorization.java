import java.io.*;

public class PrimeFactorization {
   
	public static void main(String []args) throws IOException{
		
             BufferedReader f = new BufferedReader (new InputStreamReader(System.in));
		int N = Integer.parseInt(f.readLine());
		for(int i=0; i<N; i++){
			int x = Integer.parseInt(f.readLine());
			for(int g=2; g*g <= x; g++){
				while(x % g == 0){
					System.out.print(g+" ");
					x /= g;
				}
			}
			if(x != 1) System.out.println(x);
			else System.out.println();
		}
	}
}