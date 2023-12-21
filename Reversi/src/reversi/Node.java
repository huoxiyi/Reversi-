/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package reversi;

/**
 * @class ESTR2018
 * @author Zixuan Ling
 * @email 1155191442@link.cuhk.edu.hk
 * @since 2023
 */

class State
{
    private int[] board;
    int currentPlayer;
    int[] action;
    public int actionNum;
    boolean is_terminal;
    int j;
    int actionA;
    public State(int[] cboard, int player)
    {
        board = new int[100];
        System.arraycopy(cboard, 0, board, 0, 100);
        currentPlayer = player;
        is_terminal = Reversi.isToEnd(cboard, player);
        
        for(int i = 11; i < 89; i++)
        {
            if(i%10 == 0 || i%10 == 9)
            {
                continue;
            }
            if(Reversi.isValidLocation(cboard, player, i))
            {
                actionNum += 1;
            }
        }
        //System.out.println(actionNum);
        action = new int[actionNum];
        if(actionNum == 0)
        {
            is_terminal = true;
        }
        j =0;
        for(int i = 11; i < 89; i++)
        {
            
            if(i%10 == 0)
            {
                continue;
            }
            if(Reversi.isValidLocation(cboard, player, i))
            {
                action[j]= i;
                j++;
            }
        }
        j = 0;
        shuffle(action);
    }
    
    public State(int[] cboard, int player, int act)
    {
        board = new int[100];
        actionA = act;
        System.arraycopy(cboard, 0, board, 0, 100);
        currentPlayer = player;
        is_terminal = Reversi.isToEnd(cboard, player);
        
        for(int i = 11; i < 89; i++)
        {
            if(i%10 == 0)
            {
                continue;
            }
            if(Reversi.isValidLocation(cboard, player, i))
            {
                actionNum += 1;
            }
        }
        if(actionNum == 0)
        {
            is_terminal = true;
        }
        //System.out.println(actionNum);
        action = new int[actionNum];
        j =0;
        for(int i = 11; i < 89; i++)
        {
            
            if(i%10 == 0)
            {
                continue;
            }
            if(Reversi.isValidLocation(cboard, player, i))
            {
                action[j]= i;
                j++;
            }
        }
        j = 0;
        shuffle(action);
    }
    
    int[] get_board()
    {
        int[] cBoard = new int[100];
        System.arraycopy(board, 0, cBoard, 0, 100);
        return cBoard;
    }
    
    static int get_reward(int[] gameBoard, int gamePlayer)
    {
        int result = Reversi.getWinner(gameBoard);
        //System.out.println("Player is "+ gamePlayer + "and the result is "+ result);
        //display(gameBoard, gamePlayer);
        
        if (result == gamePlayer)
            return 1;
        else if (result == 0)
            return 0;
        else return -1;
    }
    
    static void display(int[] gameBoard, int player)
    {
        System.out.print("   ");
        for(int i = 1; i <= 8; i++)
        {
            System.out.printf("%d ",i);
        }
        System.out.printf("player = %d\n", player);
        
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
    
    public static void shuffle(int[] A)
    {
        int len = A.length;
        for (int i = 0; i < len; i++)
        {
            int iRandNum = (int)(Math.random()*(len-1));
            int temp = A[iRandNum];
            A[iRandNum] = A[i];
            A[i] = temp;
        }
        
    }
    
    
    State get_next_state_randomly()
    {
        int random_choice = action[this.j];
        this.j++;
        Reversi temp = Reversi.gameCopy(this.get_board(), this.currentPlayer, random_choice);
        State next_state = new State(temp.gameBoard, temp.player, random_choice);
        return next_state;
    }
    
    State get_next_state_random()
    {
        int random_choice = action[0];

        Reversi temp = Reversi.gameCopy(this.get_board(), this.currentPlayer, random_choice);
        State next_state = new State(temp.gameBoard, temp.player, random_choice);
        return next_state;
    }
        
}


public class Node {
    Node parent;
    Node[] children;
    int visit_times;
    double quality_value;
    private State nState;
    int childrenNum;
    
    public Node(State state)
    {
        visit_times = 0;
        quality_value = 0.0;
        nState = state;
        children = new Node[state.actionNum];
        childrenNum = 0;
        parent = null;
    }
    
    State get_state()
    {
        
        return nState;
    }
    
    boolean is_all_expand()
    {
        return nState.actionNum == childrenNum;
    }
    
    void set_parent(Node parent)
    {
        this.parent = parent;
    }
    
    void add_child(Node sub_node)
    {
        sub_node.set_parent(this);
        this.children[childrenNum]=sub_node;
        childrenNum++;
        //System.out.println("Adding one child:"+childrenNum);
    }
    
    public static Node tree_policy(Node node)
    {
        while (node.get_state().is_terminal == false)
        {
            if (node.is_all_expand())
            {
                node = best_child(node, true);
            }
            else
            {
                Node sub_node = expand(node);
                return sub_node;
            }
        }
        return node;
    }
    
    public static double rollOut(Node node, Node initNode)
    {
        State currentState = node.get_state();
        while (currentState.is_terminal == false)
        {
            //State.display(currentState.get_board(), currentState.currentPlayer);
            currentState = currentState.get_next_state_random();
        }
        double finalR = State.get_reward(currentState.get_board(), initNode.get_state().currentPlayer);
        return finalR;
        
    }
    
    public static Node expand(Node node)
    {
        State newState = node.get_state().get_next_state_randomly();
        
        Node sub_node = new Node(newState);
        node.add_child(sub_node);
        return sub_node;
    }
    
    public static Node best_child(Node node, boolean is_exploration)
    {
        double bestScore = -3276777;
        Node best_sub_node = node.children[0];
        double c, left, right, score;
        for(int i = 0; i < node.childrenNum; i++)
        {
            if (is_exploration)
            {
                c = 1 / Math.sqrt(2.0);
                left = node.children[i].quality_value / node.children[i].visit_times;
                
                if (node.visit_times < 1)
                {
                    right = 0;
                }
                else
                {
                    right = Math.log(node.visit_times) / node.children[i].visit_times;
                }
                
                
                score = left + c * Math.sqrt(right);
                //System.out.println("right = "+right+" visit_times = "+node.children[i].visit_times+ " Math_log_result = " + Math.log(node.visit_times));
                if (score > bestScore)
                {
                    best_sub_node = node.children[i];
                    bestScore = score;
                    //System.out.println("change score");
                }
            }
            else
            {
                /*if (node.children[i].visit_times > bestScore)
                {
                    best_sub_node = node.children[i];
                    bestScore = node.children[i].visit_times;
                }*/
                //c = 0;
                
                left = node.children[i].quality_value / node.children[i].visit_times;
                //right = Math.log(node.visit_times) / node.children[i].visit_times;
                score = left;
                //System.out.println("children "+i+"'s quality_value/visit_times is "+score + ", visit_times = "+node.children[i].visit_times);
                if (score > bestScore)
                {
                    best_sub_node = node.children[i];
                    bestScore = score;
                    //System.out.println("change score to "+score);
                }
            }
            
            
        }
        return best_sub_node;
    }
    
    public static void backpropagation(Node node, double reward)
    {
        do
        {
            node.visit_times += 1;
            node.quality_value += reward;
            //System.out.println(node.quality_value);
            node = node.parent;
        }
        while( node.parent != null ) ;
    }
    
    public static int MCTS(Node node)
    {
        int LIMIT = 512;
        for (int i = 0; i< LIMIT; i++)
        {
            Node expand_node = tree_policy(node);
            double reward = rollOut(expand_node, node);
            backpropagation(expand_node, reward);
            //System.out.println("Round"+i);
        }
        //System.out.println(node.children.length);
        Node bnd = best_child(node, false);
        /*for(int i = 0; i < node.children.length; i++)
        {
            if (bnd.get_state().get_board() == node.children[i].get_state().get_board())
            {
                return node.get_state().action[i];
            }
        }*/
        //System.out.println(bnd.quality_value);
        return bnd.get_state().actionA;
    }
}
