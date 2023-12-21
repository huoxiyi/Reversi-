# Reversi-
The min-max reversi game is a exe document generated using C. The min-max AI player always takes the black role and moves first.
The MCTS ai player is developed using Netbeans with JDK20. The Reversi.java is the main body of the game. We prepared three dfault mode:
1. Human vs Human              2.Greedy AI vs MCTS AI                3. MCTS AI vs Human
where the former is black and the latter is white.
However, you can personalize your game.
location = newGame.humanPlayer();   \\\\This asks a human to make a move.

State ais = new State(newGame.gameBoard, [player]);
Node ai = new Node(ais);
location = Node.MCTS(ai);           \\\\This asks a move from the MCTS AI as [player], 1 being black and 2 being white.

location = ChooseFirst.stupidAI(newGame.gameBoard, [player]); \\\\This asks a move from the Greedy AI as [player], 1 being black and 2 being white.

Node.java contains the MCTS AI and ChooseFirst.java contains the Greedy AI.
