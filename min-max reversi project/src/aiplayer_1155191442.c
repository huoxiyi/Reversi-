#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ai_board[100];
int DE = 6;

void memcp_1155191442(int * a1, const int * a2, int num)
{
    for ( int i = 0; i < num; i++ )
    {
        a1[i] = a2[i];
    }
}

int check_valid_1155191442( int player, int * gb, int input )           // 1 for valid and 0 for invalid
{
    int op,i,counter=0;
    if (player == 1)
        op = 2;
    else
        op = 1;


    if ( input < 11 || input > 88 || gb[input] != 0 )
    {
        //printf("here");
        return 0;
    } 
    else //if ( gameboard[input] == 0 )
    {
        //printf("here");
        if ( gb[input-1] == op )
        {
            for ( i = 2; gb[input-i] == op; i++ )
            {
            }
            if ( gb[input-i] == player )
            {
                counter++;
            }
        }
        if ( gb[input+1] == op )
        {
            for ( i = 2; gb[input+i] == op; i++ )
            {
            }
            if ( gb[input+i] == player )
            {
                counter++;
            }
        }
        if ( gb[input-10] == op )
        {
            for ( i = 2; gb[input-i*10] == op; i++ )
            {
            }
            if ( gb[input-i*10] == player )
            {
                counter++;
            }
        }
        if ( gb[input+10] == op )
        {
            for ( i = 2; gb[input+i*10] == op; i++ )
            {
            }
            if ( gb[input+i*10] == player )
            {
                counter++;
            }
        }
        if ( gb[input-11] == op )
        {
            for ( i = 2; gb[input-i*11] == op; i++ )
            {
            }
            if ( gb[input-i*11] == player )
            {
                counter++;
            }
        }
        if ( gb[input+11] == op )
        {
            for ( i = 2; gb[input+i*11] == op; i++ )
            {
            }
            if ( gb[input+i*11] == player )
            {
                counter++;
            }
        }
        if ( gb[input+9] == op )
        {
            for ( i = 2; gb[input+i*9] == op; i++ )
            {
            }
            if ( gb[input+i*9] == player )
            {
                counter++;
            }
        }
        if ( gb[input-9] == op )
        {
            for ( i = 2; gb[input-i*9] == op; i++ )
            {
            }
            if ( gb[input-i*9] == player )
            {
                counter++;
            }
        }

        if ( counter == 0 )
            return 0;
        else
            return 1;       
    }
    //return 0;
}

int check_pass_1155191442 ( int player, int * gb )          //1 for pass and 0 for no passing
{
    int i, j;
    for ( i=11; i<89; i++ )
    {
        if (gb[i] == 0)
        {
            if (check_valid_1155191442(player,gb,i)==1)
                return 0;
        }
    }
    
    return 1;
}

int check_steady_1155191442( int pos, int * gb )
{
    int check_1=0, check_2=0,check_3=0,check_4=0, i, j;
    for ( i = 1; gb[pos-i]==gb[pos]; i++ ){}
    for ( j = 1; gb[pos+j]==gb[pos]; j++ ){}
    if (gb[pos-i]==3||gb[pos+j]==3)
    {
        check_1++;
    }

    for ( i = 1; gb[pos-i*10]==gb[pos]; i++ ){}
    for ( j = 1; gb[pos+j*10]==gb[pos]; j++ ){}
    if (gb[pos-i*10]==3||gb[pos+j*10]==3)
    {
        check_2++;
    }

    for ( i = 1; gb[pos-i*11]==gb[pos]; i++ ){}
    for ( j = 1; gb[pos+j*11]==gb[pos]; j++ ){}
    if (gb[pos-i*11]==3||gb[pos+j*11]==3)
    {
        check_3++;
    }

    for ( i = 1; gb[pos-i*9]==gb[pos]; i++ ){}
    for ( j = 1; gb[pos+j*9]==gb[pos]; j++ ){}
    if (gb[pos-i*9]==3||gb[pos+j*9]==3)
    {
        check_4++;
    }

    if ( check_1 * check_2 * check_3 * check_4 == 0 )
        return 0;
    else
        return 1;
}

int check_frontier_1155191442 ( int pos, int * gb )
{
    int counter = 0;
    if ( gb[pos+1] == 0 )
        counter++;
    if ( gb[pos+10] == 0 )
        counter++;
    if ( gb[pos+11] == 0 )
        counter++;
    if ( gb[pos+9] == 0 )
        counter++;
    if ( gb[pos-1] == 0 )
        counter++;
    if ( gb[pos-10] == 0 )
        counter++;
    if ( gb[pos-11] == 0 )
        counter++;
    if ( gb[pos-9] == 0 )
        counter++;
      
    return counter;
}

void flip_1155191442(int player, int * gb, int input)
{
    int op,i,j;
    if (player == 1)
        op = 2;
    else
        op = 1;

    if (gb[input - 1] == op)
    {
        for (i = 2; gb[input - i] == op; i++)
        {
        }
        if (gb[input - i] == player)
        {
            for ( j = 0; j < i; j++ )
            {
                gb[input - j] = player;
            }
        }
    }
    if (gb[input + 1] == op)
    {
        for (i = 2; gb[input + i] == op; i++)
        {
        }
        if (gb[input + i] == player)
        {
            for ( j = 0; j < i; j++ )
            {
                gb[input + j] = player;               
            }
        }
    }
    if (gb[input - 10] == op)
    {
        for (i = 2; gb[input - i * 10] == op; i++)
        {
        }
        if (gb[input - i * 10] == player)
        {
            for ( j = 0; j < i; j++ )
            {
                gb[input - j*10] = player;
            }
        }
    }
    if (gb[input + 10] == op)
    {
        for (i = 2; gb[input + i * 10] == op; i++)
        {
        }
        if (gb[input + i * 10] == player)
        {
            for ( j = 0; j < i; j++ )
            {
                gb[input + j*10] = player;
                //printf("\n %d %d \n",gameboard[input+i],input+i);
            }
        }
    }
    if (gb[input - 11] == op)
    {
        for (i = 2; gb[input - i * 11] == op; i++)
        {
        }
        if (gb[input - i * 11] == player)
        {
            for ( j = 0; j < i; j++ )
            {
                gb[input - j*11] = player;
            }
        }
    }
    if (gb[input + 11] == op)
    {
        for (i = 2; gb[input + i * 11] == op; i++)
        {
        }
        if (gb[input + i * 11] == player)
        {
            for ( j = 0; j < i; j++ )
            {
                gb[input + j*11] = player;
            }
        }
    }
    if (gb[input + 9] == op)
    {
        for (i = 2; gb[input + i * 9] == op; i++)
        {
        }
        if (gb[input + i * 9] == player)
        {
            for ( j = 0; j < i; j++ )
            {
                gb[input + j*9] = player;
            }
        }
    }
    if (gb[input - 9] == op)
    {
        for (i = 2; gb[input - i * 9] == op; i++)
        {
        }
        if (gb[input - i * 9] == player)
        {
            for ( j = 0; j < i; j++ )
            {
                gb[input - j*9] = player;
            }
        }
    }
}

int eveluation_1155191442(int player)//when depth=6
{
    int op_player = 3 - player;
    int mobility = 0, i, parity = 0, steady = 0, frontier = 0, temp, num_0 = 0, result, corner = 0, position = 0;
    int weight[100] = {0,0,0,0,0,0,0,0,0,0,\
                       0,600,-90,40,10,10,40,-90,600,0,\
                       0,-90,-300,1,1,1,1,-300,-90,0,\
                       0,40,1,8,5,5,8,1,40,0,\
                       0,10,1,5,1,1,5,1,10,0,\
                       0,10,1,5,1,1,5,1,10,0,\
                       0,40,1,8,5,5,8,1,40,0,\
                       0,-90,-300,5,5,5,5,-300,-90,0,\
                       0,600,-90,40,10,10,40,-90,600,0};
    for ( i = 11; i < 89; i++)
    {
        if ( ai_board[i] == 0 )
        {
            num_0++;
            mobility += check_valid_1155191442( player, ai_board, i );
        }       //  calculate mobility
        else if ( ai_board[i] == player )
        {
            temp = check_steady_1155191442(i,ai_board);
            steady += temp;
            position += weight[i];
            if ( temp == 0 )
                frontier -= check_frontier_1155191442(i,ai_board);
            
        }
        else if ( ai_board[i] == op_player )
        {
            temp = check_steady_1155191442(i,ai_board);
            steady -= temp;
            position -= weight[i];
            if ( temp == 0 )
                frontier += check_frontier_1155191442(i,ai_board);
        }       // calculate steady, frontier
    }

    if (player == 1)
    {
        if ( num_0 % 2 == 0 )
        {
            parity = -1;
        }
        else
        parity = 1;
    }
    else
    {
        if ( num_0 % 2 == 0 )
        {
            parity = 1;
        }
        else
        parity = -1;
    }           //calculate the parity
    
    if ( ai_board[11] == 0 )
    {
        if ( ai_board[12] == player )
        {
            corner -= 6;
        }
        else if ( ai_board[12] == op_player )
        {
            corner += 6;
        }

        if ( ai_board[21] == player )
        {
            corner -= 6;
        }
        else if ( ai_board[21] == op_player )
        {
            corner += 6;
        }

        if ( ai_board[22] == player )
        {
            corner -= 12;
        }
        else if ( ai_board[22] == op_player )
        {
            corner += 12;
        }
    }
    else if ( ai_board[11] == player )
        corner += 40;
    else if ( ai_board[11] == op_player )
        corner -= 40;

    if ( ai_board[18] == 0 )
    {
        if ( ai_board[17] == player )
        {
            corner -= 6;
        }
        else if ( ai_board[17] == op_player )
        {
            corner += 6;
        }

        if ( ai_board[28] == player )
        {
            corner -= 6;
        }
        else if ( ai_board[28] == op_player )
        {
            corner += 6;
        }

        if ( ai_board[27] == player )
        {
            corner -= 12;
        }
        else if ( ai_board[27] == op_player )
        {
            corner += 12;
        }
    }
    else if ( ai_board[18] == player )
        corner += 40;
    else if ( ai_board[18] == op_player )
        corner -= 40;

    if ( ai_board[81] == 0 )
    {
        if ( ai_board[82] == player )
        {
            corner -= 6;
        }
        else if ( ai_board[82] == op_player )
        {
            corner += 6;
        }

        if ( ai_board[71] == player )
        {
            corner -= 6;
        }
        else if ( ai_board[71] == op_player )
        {
            corner += 6;
        }

        if ( ai_board[72] == player )
        {
            corner -= 12;
        }
        else if ( ai_board[72] == op_player )
        {
            corner += 12;
        }
    }
    else if ( ai_board[81] == player )
        corner += 40;
    else if ( ai_board[81] == op_player )
        corner -= 40;

    if ( ai_board[88] == 0 )
    {
        if ( ai_board[78] == player )
        {
            corner -= 6;
        }
        else if ( ai_board[78] == op_player )
        {
            corner += 6;
        }

        if ( ai_board[87] == player )
        {
            corner -= 6;
        }
        else if ( ai_board[87] == op_player )
        {
            corner += 6;
        }

        if ( ai_board[77] == player )
        {
            corner -= 12;
        }
        else if ( ai_board[77] == op_player )
        {
            corner += 12;
        }
    }
    else if ( ai_board[88] == player )
        corner += 40;
    else if ( ai_board[88] == op_player )
        corner -= 40;               // calculate corner

    
    result = corner*45 + steady*165 + frontier*30 + mobility*140 + parity*45 + position;
    return result;
}

int ai_1155191442( int player, int ai_board[], int depth, int alpha, int beta, int pass )
{
    int bv = -327677, winner, bi = 0, i = 0, cp=0, co=0, sgn;
    int *bo ;
    bo = (int *)malloc(100*sizeof(int));
    memcp_1155191442(bo,ai_board,100);

    if (check_pass_1155191442(player, ai_board) == 1)
    {
        if (pass == 1)
        {
            for ( i = 11; i < 82; i++ )
            {
                if ( ai_board[i] == player )
                {
                    cp++;
                }
                else if ( ai_board[i] == 3-player )
                {
                    co++;
                }
            }
            
            if (cp!=co)
                return 1000*(cp-co); 
            else 
                return 1000 ;
        }
        else
        {
            bv = -ai_1155191442(3 - player, ai_board, depth , -beta, -alpha, 1);
        }
    }
    else
    {
        //printf("\nhere\n");
        for ( i = 11; i < 89; i++)
        {
            
            if (check_valid_1155191442(player, ai_board, i)==1)
            {
                int v;              
                flip_1155191442(player, ai_board, i);
                if (depth == 1)
                {
                    v = -1 * eveluation_1155191442(3-player);
                    //printf("%d\n",v);
                }    
                else if (bv == -327677 || (v = -ai_1155191442(3-player, ai_board, depth - 1, -alpha - 1, -alpha,0)) > alpha && (alpha = v) < beta)
                {
                    v = -ai_1155191442(3-player, ai_board, depth - 1, -beta, -alpha,0);
                }
                
                memcp_1155191442(ai_board, bo, 100);
                //display(ai_board);
                
                if (v >= beta)
                {
                    //printf("\nhere d:%d\n",depth);
                    
                    if ( depth == DE )
                    {
                        //printf("\ni:%d\n",i);                   
                        return i;
                    }
                    else
                        return v;
                }

                if (v > bv)
                {
                    //printf("\nhere i:%d\n",i);
                    
                    bv = v;
                    if ( depth == DE )
                        {
                            bi = i;
                            //printf("\n\ni:%d\n",i);
                        }
                    if (v > alpha)
                        alpha = v;
                }
            }
        }
    }
    free (bo);
    if ( depth == DE )
    {
        //printf("\nbi:%d\n\n",bi);
        
        return bi;
    }    
    else
        return bv;
}

int ai_player_1155191442( int player , const int * board )
{
    //int * gb = board;
    memcp_1155191442(ai_board,board,100);
    int i = ai_1155191442(player, ai_board, DE,-327677,327677,0);
    //printf("%d",i);
    return i;
}