#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aiplayer_1155191442.h"
int gameboard[100];

//int pass_flag[2]= {0};

void memcp(int * a1, int * a2, int num)
{
    for ( int i = 0; i < num; i++ )
    {
        a1[i] = a2[i];
    }
}

void initialize()
{
    memset(gameboard,0,100);
    gameboard[45] = 1;
    gameboard[54] = 1;
    gameboard[44] = 2;
    gameboard[55] = 2;
    for ( int i = 0; i < 11; i ++ )
    {
        gameboard[i] = 3;
        gameboard[i*10+9] = 3;
        gameboard[i*10] = 3;
    }    
}

void test_initialize()
{
    memset(gameboard,0,100);
    gameboard[13] = 2;
    gameboard[14] = 2;
    gameboard[15] = 1;
    gameboard[16] = 1;
    gameboard[23] = 2;
    gameboard[24] = 2;
    gameboard[25] = 1;
    gameboard[26] = 1;
    gameboard[28] = 2;
    gameboard[31] = 1;
    gameboard[32] = 1;
    gameboard[33] = 1;
    gameboard[34] = 1;
    gameboard[35] = 2;
    gameboard[36] = 1;
    gameboard[37] = 2;
    gameboard[38] = 2;
    gameboard[41] = 1;
    gameboard[42] = 1;
    gameboard[43] = 1;
    gameboard[44] = 1;
    gameboard[45] = 2;
    gameboard[46] = 2;
    gameboard[47] = 1;
    gameboard[48] = 2;
    gameboard[51] = 2;
    gameboard[52] = 1;
    gameboard[53] = 1;
    gameboard[54] = 1;
    gameboard[55] = 2;
    gameboard[56] = 1;
    gameboard[57] = 1;
    gameboard[58] = 2;
    gameboard[61] = 2;
    gameboard[62] = 2;
    gameboard[63] = 1;
    gameboard[64] = 2;
    gameboard[65] = 2;
    gameboard[66] = 2;
    gameboard[67] = 1;
    gameboard[68] = 2;
    gameboard[72] = 2;
    gameboard[73] = 2;
    gameboard[74] = 1;
    gameboard[75] = 2;
    gameboard[76] = 1;
    gameboard[77] = 1;
    gameboard[78] = 2;
    gameboard[81] = 2;
    gameboard[82] = 2;
    gameboard[83] = 2;
    gameboard[84] = 2;
    gameboard[85] = 2;
    gameboard[86] = 2;
    gameboard[87] = 1;
    gameboard[88] = 2;
    for ( int i = 0; i < 11; i ++ )
    {
        gameboard[i] = 3;
        gameboard[i*10+9] = 3;
        gameboard[i*10] = 3;
    }
 
}

void display(int * gb)
{
    int num_1=0, num_2=0;
     
    for ( int i = 0; i < 100; i++ )
    {
        if ( gb[i] == 1 )
        {
            //board[i] = '#';
            num_1++;
        }    
        else if ( gb[i] == 2 )
        {
            //board[i] = 'O';
            num_2++;
        }    
    }
    printf("   1 2 3 4 5 6 7 8 [#=%d O=%d]\n",num_1,num_2);
    for ( int i = 1; i < 9; i++ )
    {
        printf("%d ",i);
        for ( int j = 1; j < 9; j++ )
        {
            if ( gb[i*10+j] == 0)
                printf(" .");
            if ( gb[i*10+j] == 1)
                printf(" #");
            if ( gb[i*10+j] == 2)
                printf(" O");
        }
        printf("\n");
    }
}

int human_player_1155191442 ( int player, const int * gameboard )
{
    int input;
    scanf("%d",&input);
    return input;
}

int check_valid( int player, int * gb, int input )           // 1 for valid and 0 for invalid
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

int check_pass ( int player, int * gb )          //1 for pass and 0 for no passing
{
    int i, j;
    for ( i=11; i<89; i++ )
    {
        if (gb[i] == 0)
        {
            if (check_valid(player,gb,i)==1)
                return 0;
        }
    }
    
    return 1;
}

int check_end(int * gb,int flag)                  //1 for winner 1 , 2 for winner 2 , 3 for draw , 0 for not the end
{
    int i, counter_1 = 0, counter_2 = 0;
    
    for ( i = 11; i < 89; i++ )
    {
        if ( gb[i] == 1 )
        {
            counter_1++;
        }
        else if ( gb[i] == 2 )
        {
            counter_2++;
        }
    }
    if (flag==1)
    {
        if ( counter_1 > counter_2 )
            return 1;
        else if ( counter_1 < counter_2 )
            return 2;
        else if ( counter_1 == counter_2 )
            return 3;
    }
    if ( counter_1 == 0)
        return 2;
    if ( counter_2 == 0)
        return 1;

    if (counter_1 + counter_2 == 64 )
    {   if ( counter_1 > counter_2 )
            return 1;
        else if ( counter_1 < counter_2 )
            return 2;
        else if ( counter_1 == counter_2 )
            return 3;
    }
    else    
        return 0; 
}



void flip(int player, int * gb, int input)
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



int main(void)
{
    initialize();
    //test_initialize();
    
    int player = 1, input, winner, i, flag=0;


    /*memcp(ai_board[5], gameboard, 100);
    display(gameboard);
    display(ai_board[5]);
    printf("\n%d",eveluation(1));*/



    while(1)
    {        
        winner = 0;
        if ( check_pass( player, gameboard ) == 1)
        {
            //pass_flag[player-1] = 1;
            winner = check_end(gameboard,flag);
            if ( winner != 0 || flag==1 )
            {
                if ( winner == 1 )
                    printf("\nblack");
                else if ( winner == 2 )
                    printf("\nwhite");
                else if ( winner == 3 )
                    printf("\ndraw");
                printf("winner=%d",winner);
                break;
            }
            else
            {
                flag==1;
                printf("\npass\n");
                if ( player == 1 )
                    player = 2;
                else
                    player = 1;
                continue;
            }
        }
        else
        {
            //pass_flag[player-1] = 0;
            display(gameboard);
            flag==0;
            if ( player == 1 )
            {
                input = ai_player_1155191442(1,gameboard);
            }
            else
                input = human_player_1155191442(player, gameboard);
                printf("\n%d\n\n",input);
            while( check_valid(player, gameboard, input ) == 0 )
            {
                printf("invalid input, try again\n");
                input = human_player_1155191442(player, gameboard);
            }
            //printf("here");
            flip(player, gameboard, input);
            
            if ( player == 1 )
                {
                    printf("player balck input location %d\n",input);
                    player = 2;
                }  
                else
                {
                    printf("player white input location %d\n",input);
                    player = 1;
                }    
                continue;
        }

    }

    
    return 0;
}