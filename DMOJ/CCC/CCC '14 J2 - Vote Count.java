import java.io.*;

public class ClassProblem 
{

    public static void main(String[] args) {
        new ClassProblem();
    }
    public ClassProblem()
    {
     try
     {
         BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
         int voteNumber = Integer.parseInt(in.readLine());
         int a = 0;
         int b = 0;
         
         String votes = in.readLine();
         
         for(int i = 0; i < voteNumber; i++)
             
            if(votes.charAt(i) == 'A'){
                a++;
            }
            
            else{
                b++;    
                    }
                    System.out.println((a > b) ? ("A") : (b > a) ? ("B") : ("Tie"));
     }
     catch (IOException e)
     {
         
     }
           
    }
}