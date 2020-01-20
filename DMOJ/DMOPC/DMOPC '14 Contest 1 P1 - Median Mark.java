import java.util.*;
public class MedianMark {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int arr [] = new int [n];
        for (int i = 0; i < n; i++){
             arr [i] = in.nextInt();
    }
        Arrays.sort(arr);
        if ((n & 1) == 0)
            System.out.println((int) (Math.round((arr[n >> 1] + arr[(n >> 1) - 1]) / 2.0)));
        else 
            System.out.println(Math.round(arr[n >> 1]));
    }
}