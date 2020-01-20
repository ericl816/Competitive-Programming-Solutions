import java.io.*;
public class Main {
static int n;
static String a, b, c, d, e;
    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader (new InputStreamReader(System.in));
      switch (Integer.parseInt(in.readLine())) {
      case 0:
        System.out.print(" * * *\n*     *\n*     *\n*     *\n\n*     *\n*     *\n*     *\n * * *\n");
        break;
      case 1:
        System.out.print("      *\n      *\n      *\n\n      *\n      *\n      *\n");
        break;
      case 2:
        System.out.print(" * * *\n       *\n       *\n       *\n * * *\n*\n*\n*\n * * *\n");
        break;
      case 3:
        System.out.print(" * * *\n       *\n       *\n       *\n * * *\n       *\n       *\n       *\n * * *\n");
        break;
      case 4:
        System.out.print("*     *\n*     *\n*     *\n * * *\n      *\n      *\n      *");
        break;
      case 5:
        System.out.print(" * * *\n*\n*\n*\n * * *\n      *\n      *\n      *\n * * *\n");
        break;
      case 6:
        System.out.print(" * * *\n*\n*\n*\n * * *\n*      *\n*      *\n*      *\n * * *\n");
        break;
      case 7:
        System.out.print(" * * *\n      *\n      *\n\n      *\n      *\n      *\n");
        break;
      case 8:
        System.out.print(" * * *\n*     *\n*     *\n*     *\n * * *\n*     *\n*     *\n*     *\n * * *\n");
        break;
      case 9:
        System.out.print(" * * *\n*     *\n*     *\n*     *\n * * *\n      *\n      *\n      *\n * * *\n");
    }
    }   
}