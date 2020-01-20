import java.io.*;
public class fightme {

public static void main(String args[]) throws IOException {
BufferedReader fi = new BufferedReader (new InputStreamReader(System.in));
int a = Integer.parseInt(fi.readLine());
int b = Integer.parseInt(fi.readLine());
    for (int i = 0; i < b; i++) {
int c = Integer.parseInt(fi.readLine());
int d = Math.abs(a-c);
    if (d > 100) {
    System.out.println("go away! 3:<");
    }
    else if(d<=100) {
    System.out.println("fite me! >:3");
    }
}
}
}