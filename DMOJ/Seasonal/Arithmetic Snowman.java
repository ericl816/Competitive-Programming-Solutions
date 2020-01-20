import java.util.*;

public class ArithmeticSnowman {
    
    public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    int n = in.nextInt(), ans=0;
    int [] arr = new int [n];
    for (int i = 0; i < n; i++)
        arr [i] = in.nextInt();
    
    // Sort array
    Arrays.sort(arr);
    // Loop through array for a3 & a2
    for (int a3 = n-1; a3 >= 0; a3--){
        for (int a2 = a3-1; a2 >= 0; a2--){
            int a1 = arr[a2]-(arr[a3]-arr[a2]);
            
            // Index for BinarySearch (Parameters of 0 and a1)
            int index = Arrays.binarySearch(arr, 0, a2, a1);
            if (index >= 0){
                // Summation of three values (Index = a1)
                ans = Math.max(ans, arr[index]+arr[a2]+arr[a3]);
                break;
            }
          }
        }
    System.out.println(ans);
        
    }
}