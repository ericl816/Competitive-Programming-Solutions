import java.io.*;
import java.util.*;
public class Problem {
  
    public static void main(String[] args) {
       new Problem();
       
    }
    public Problem(){
        try
        {
    BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
    int sessions = Integer.parseInt(in.readLine());
    int player1 = 100;
    int player2 = 100;
    
    for(int i = 0; i < sessions; i++) {
        
     StringTokenizer st = new StringTokenizer(in.readLine());
     
    int diceRollP1 = Integer.parseInt(st.nextToken());
    int diceRollP2 = Integer.parseInt(st.nextToken());
    
    if(diceRollP1 > diceRollP2)
        player2 = player2 - diceRollP1;
    
    else 
        if(diceRollP2 > diceRollP1)
            player1 = player1 - diceRollP2;
    }
    System.out.println(player1);
    System.out.println(player2);
 }
        
catch (IOException e) {
    
    }
  }
    
}