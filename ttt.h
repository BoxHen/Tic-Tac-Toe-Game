/* Functions are defined in ttt.c */

/* Make a data type for "player" functions */
/*   A player function is a function which takes a board and a token, and returns
     a best move.  The game is made up of invoking the two player functions
     against each other */
typedef char (*player)(char board[3][3],char XO);

/* The playGame function invokes each player function in turn until either
    one of the players wins, or the players tie */
void playGame(player player1, player player2);

/* The drawBoard function draws the playing board */
void drawBoard(char board[3][3]);

/* The winner function returns the token of the winner (X or O) if there is a
    winner on the board.  Otherwise, returns a blank */
char winner(char board[3][3]);

/* The isTie function returns 1 if the board is a tie, 0 otherwise */
int isTie(char board[3][3]);

/* The getTriplet function returns three characters in one of the rows, columns,
    or diagonals of the tic-tac-toe board.
    There are 8 triplets on the board, which can be numbered...
    		0 - Top Row
    		1 - Middle Row
    		2 - Bottom Row
    		3 - Left column
    		4 - Middle column
    		5 - Right column
    		6 - Right to Left diagonal
    		7 - Left to Right diagnoal
    To win at tic-tac-tow, you must have a single token (X or O) in all three elements
    of one of the 8 triplets. */
char * getTriplet(char board[3][3],int tnum);

/* Returns the token that fills all three elements of the triplet if there is such a token
   Returns a blank otherwise. */
char tripletWinner(char trip[3]);

/* Returns a 1 if both X and O are in this triplet (and therefore this triplet cannot be a winner) */
int isTripTie(char trip[3]);

/* Returns the unchosen entry in this triplet if both of the other entries in the triplet are XO */
/* Otherwise, returns blank */
char trip1MoveWinner(char trip[3],char XO);

/* Returns a 0 if there is an X or O on the board at char pos, 1 otherwise */
int isAvail(char board[3][3],char pos);

/* Returns the Row number of a position character */
int charToRow(char pos);

/* Returns the Column number of a position character */
int charToCol(char pos);

/* Checks to see if the argument is a position character */
int isPositionChar(char pos);

/* Returns X if XO is O, and O if XO is X */
char opponent(char XO);

/* Returns 1 if XO is either 'X' or 'O'... 0 otherwise */
int isXO(char XO);