/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package reversi;

/**
 *
 * @class ESTR2018
 * @author Yongjiang Wu
 * @email 1155191540@link.cuhk.edu.hk
 *
 * @author Zixuan Ling
 * @email 1155191442@link.cuhk.edu.hk
 * @since 2023
 */
public class ChooseFirst {
    
    public static int stupidAI(int[] gameBoard, int player){
        //return first valid location
        int init = -32767;
        int bestL = 11;
        int temp;
        for(int j = 1; j <= 8; j++)
            for(int i = 1; i <= 8; i++)
            {
               if(Reversi.isValidLocation(gameBoard, player, j*10+i))
               {
                   temp = returnPiecesDif(Reversi.gameCopy(gameBoard, player, j*10+i).gameBoard, Reversi.gameCopy(gameBoard, player, j*10+i).player);
                   if (temp > init)
                   {
                       init = temp;
                       bestL = j*10+i;
                   }
               }
            }
        
        return bestL;
    }
    
    static int returnPiecesDif(int[] gameBoard, int player)
    {
        //initialize
        int blackPieces = 0;
        int whitePieces = 0;
        
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
        if(player == 1)
        {
            return blackPieces - whitePieces;
        }
        else return -(blackPieces - whitePieces);
    }
    
}
