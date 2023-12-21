/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package reversi;

import java.util.InputMismatchException;
import java.util.Scanner;

// 1 for black
// 2 for white
// 3 for boundry
// 0 for empty

// 'O' represents the white piece (2)
// '#' represents the black piece (1)
// '.' represents the empty cell  (0)

/**
 * @class ESTR2018
 * @author Yongjiang Wu
 * @email 1155191540@link.cuhk.edu.hk
 * @since 2023
 */

public class Reversi {
    //Instance field
    //can be accessed by packages, referring to the gameboard
    public int[] gameBoard = new int[100];
    private int blackPieces = 2;
    private int whitePieces = 2;
    public int player;
    private static final String[] playerType = {"","black","white"};
    //new created purpose
    static int win = 0;
    
    
    public Reversi()
    {
        super();
        System.err.println("Cannot creat a new game!");
    }
    
    public Reversi(int pieceType)
    {
        player = pieceType;
    }
    
    public Reversi(int[] passedBoard, int pieceType)
    {
        for(int i = 0; i < 100; i++)
        {
            this.gameBoard[i] = passedBoard[i];
        }
        
        this.player = pieceType;

    }
    
    //method to initialize the gameboard
    private void gameBoardInit()
    {
       for(int i = 0; i <= 99; i++)
       {
           // set boundry
           if(i/10 == 0 || i/10 == 9 || i%10 == 9 || i%10 == 0)
               gameBoard[i] = 3;
           
           // set white
           if(i == 44 || i == 55)
               gameBoard[i] = 2;
           
           //set black
           if(i == 45 || i == 54)
               gameBoard[i] = 1;
           
           //init instance field
           blackPieces = 2;
           whitePieces = 2;
       }
    }
    
    //display gameboard
    private void gameBoardDisplay()
    {
        // i stands for col, j stands for row
        //print the first line
        System.out.print("   ");
        for(int i = 1; i <= 8; i++)
        {
            System.out.printf("%d ",i);
        }
        System.out.printf("[#=%d O=%d]\n",blackPieces,whitePieces);
        
        //the remaining lines
        for(int j = 1; j <= 8; j++)
        {
            System.out.printf("%d  ",j);
            for(int i = 1; i <= 8; i++)
            {
                int index = j*10 + i;
                
                //print .
                if(gameBoard[index] == 0)
                    System.out.print(". ");
                
                //print #
                if(gameBoard[index] == 1)
                    System.out.print("# ");
                
                //print O
                if(gameBoard[index] == 2)
                    System.out.print("O ");
            }
            
            //newline character
            System.out.println("");
        }
    }
    
    //read human input
    private int humanPlayer()
    {
        Scanner scan = new Scanner(System.in);
        System.out.print("Please input next move: ");
        
        int input = 0;
        try{
            input = scan.nextInt();
        }
        catch(InputMismatchException e)
        {
            System.out.println("Invalid input!");
        }
        
        return input;
    }
            
    public static boolean isValidLocation(int[] gameBoard, int player, int location)
    {
        //check if on board
        if(location > 88 ||location < 11)
            return false;
        else{
             //check if it is empty
             if(gameBoard[location] != 0)
                 return false;
             else{
                 //check if disc can be flipped
                 //eight directions :[leftUp, Up, rightUp, left, right, leftDown, Down, rightDown]
                 int[] direction = {-11, -10, -9, -1, 1, 9, 10, 11};
                 
                 // to store whether a valid path exists
                 boolean isValid = false;
                 
                 int rival = 3 - player;
                 
                 for(int i = 0; i < 8; i++)
                 {
                     int locationSearch = location + direction[i];
                     if(gameBoard[locationSearch] == rival)
                     {
                         // loop all opponent disc
                         while(gameBoard[locationSearch] == rival)
                             locationSearch += direction[i];
                         // loop ends when reaching empty/itself/boundry
                         
                         //check if there exists a original disc
                         if(gameBoard[locationSearch] == player)
                         {
                             isValid = true;
                             break;
                         }
                     }
                 }
                 
                 return isValid;
             }
        }

    }
    
    private void changePlayer()
    {
        player = 3 - player;
    }
    
    private void updatePiecesNum()
    {
        //initialize
        blackPieces = 0;
        whitePieces = 0;
        
        for(int j = 1; j <= 8; j++)
        {
            for(int i = 1; i <= 8; i++)
            {
                 if(gameBoard[j*10 + i] == 1)
                     blackPieces++;
                 else if(gameBoard[j*10 + i] == 2)
                     whitePieces++;
            }
        }
    }
    
    public static boolean isToPass(int[] gameBoard, int player)
    {
        //i stands for col, j stands for row
        boolean toPass = true;
        for(int j = 1; j <= 8; j++)
        {
            for(int i = 1; i <= 8; i++)
            {
                if(isValidLocation(gameBoard, player, j*10 + i))
                {
                    toPass = false;
                    break;
                }
            }
        }
        
        return toPass;
    }
    
    public static boolean isToEnd(int[] gameBoard, int player)
    {   
        //check if gameboard is full
        boolean isFull = true;
        for(int j = 1; j <= 8 ; j++)
            for(int i = 1; i <= 8; i++)
            {
                if(gameBoard[j*10+i] == 0)
                {
                    isFull = false;
                    break;
                }
            }
        
        if(isFull)
            return true;
        
        // not full
        if(isToPass(gameBoard, player))
            if(isToPass(gameBoard, 3-player))
                // both players pass
                return true;
        
        // not all passes
        return false;
        
    }
    
    public static void operateGameBoard(int[] gameBoard, int player, int location)
    {
        //place the disc and update
        gameBoard[location] = player;
        
        //flip rival's discs
        
        // find valid path to do the operation
        //eight directions :[leftUp, Up, rightUp, left, right, leftDown, Down, rightDown]
        int[] direction = {-11, -10, -9, -1, 1, 9, 10, 11};
        
        // flag use to record if valid path exists, default false
        boolean[] isValid;    //initialze to be no valid paths
        isValid = new boolean[8];
        
        int rival = 3 - player;
        
        // find all valid paths, index is i
        for(int i = 0; i < 8; i++)
        {
             int locationSearch = location + direction[i];
             if(gameBoard[locationSearch] == rival)
             {
                 // loop all opponent disc
                 while(gameBoard[locationSearch] == rival)
                     locationSearch += direction[i];
                 // loop ends when reaching empty/itself/boundry
                    
                 //check if there exists a original disc
                 if(gameBoard[locationSearch] == player)
                     isValid[i] = true;
             }
        } 
        
        //flip all valid paths
        for(int i = 0; i < 8; i++)
        {
            if(isValid[i])
            {
                int locationSearch = location + direction[i];
                while(gameBoard[locationSearch] == rival)
                {
                    //flip disc
                    gameBoard[locationSearch] = player;
                    
                    locationSearch += direction[i];
                }
            }
        }
    }
    
    //1 stands for black wins, 2 stands for white wins, 0 stands for draw
    public static int getWinner(int[] gameBoard)
    {
        // b means black, w means white
        int b = 0;
        int w = 0;
        for(int j = 1; j <= 8; j++)
            for(int i =1; i<= 8; i++)
            {
                if(gameBoard[j*10 + i] == 1)
                    b++;
                else if(gameBoard[j*10 + i] == 2)
                    w++;
            }
        
        //draw
        if(b == w)
            return 0;
        
        //black wins
        else if(b > w)
            return 1;
        
        //white wins
        else
            return 2;
    }
    
    private void displayResult()
    {
        if(blackPieces > whitePieces)
            System.out.println("Black wins!");
        else if(whitePieces > blackPieces){
            //new created purpose
            win++;
            System.out.println("White wins!");
        }
        else
            System.out.println("Draw!");
    }
    
    public static Reversi gameCopy(int[] gameBoard, int player, int location)
    {
        Reversi rCopy = new Reversi(gameBoard,player);
        operateGameBoard(rCopy.gameBoard,rCopy.player,location);
        rCopy.changePlayer();
        
        //check if needs to pass
        while(Reversi.isToPass(rCopy.gameBoard,rCopy.player)){
            //check if ends
            if(Reversi.isToEnd(rCopy.gameBoard, rCopy.player))
                break;
            
            //not ends, passes
            rCopy.changePlayer();
        }
        
        return rCopy;
    }
            
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // choose game mode, 1 means human vs human, 2 means human vs ai, 3 means ai vs human
        int mode = 1;
        Scanner scan = new Scanner(System.in);
        
        try{
            System.out.println("Choose the game mode. 1: human vs human, 2: human vs AI, 3: MCTS(Black) vs Greedy(White).");
            mode = scan.nextInt();
        }
        catch(InputMismatchException e){
            System.out.println("Invalid mode input! Game starts with default mode: human vs human.");
        }
        
        if(mode < 1 || mode > 3){
            mode = 1;
        }
        
        
        
        //new loop purpose
        for(int i = 1 ;i <=500 ; i++){
        //creat a new game, default black
        int pieceType = 1;
        Reversi newGame = new Reversi(pieceType);
        newGame.gameBoardInit();
        while(true)
        {
            //newGame.gameBoardDisplay();
            //need to pass
            if(Reversi.isToPass(newGame.gameBoard,newGame.player)){
                if(Reversi.isToEnd(newGame.gameBoard,newGame.player)){
                    //end of game
                    newGame.displayResult();
                    //quit loop
                    break;
                }
                //else print message and change player
                System.out.printf("Player %s passes.\n",playerType[newGame.player]);
                newGame.changePlayer();
            }
            
            // no passes
            else{
                //get a valid move and print the move
                int location;
                while(true)
                {
                    //mode 1: human vs human
                    if(mode == 1)
                        location = newGame.humanPlayer();
                    //mode 2: human vs ai
                    else if(mode == 2){
                        if(newGame.player == 1)
                            //location = newGame.humanPlayer();
                            location = ChooseFirst.stupidAI(newGame.gameBoard, 1);
                        else
                        {   
                            State ais = new State(newGame.gameBoard, 2);
                            Node ai = new Node(ais);
                            location = Node.MCTS(ai);
                        }
                    }
                    //mode 3: ai vs human
                    else{
                         if(newGame.player == 2)
                             location = newGame.humanPlayer();
                             //location = ChooseFirst.stupidAI(newGame.gameBoard, 2);
                         else
                         {    
                            State ais = new State(newGame.gameBoard, 1);
                            Node ai = new Node(ais);
                            location = Node.MCTS(ai);
                         }
                    }
                    
                    //check if valid
                    if(Reversi.isValidLocation(newGame.gameBoard, newGame.player, location)) {
                        break;
                    }
                }
                
                System.out.printf("Player %s input location: %d\n",Reversi.playerType[newGame.player],location);
                
                //flip rival's discs
                Reversi.operateGameBoard(newGame.gameBoard,newGame.player,location);
                newGame.updatePiecesNum();
                //change player
                newGame.changePlayer();
            }    
        }
        
        }
        // new loop purpose
        System.out.println("MCTS beats Greedy "+ Reversi.win +" times out of 100 times!");
    }
   
    
}
