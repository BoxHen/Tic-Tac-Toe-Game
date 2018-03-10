#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ttt.c"

player choosePlayer(char XO);
char humanChoice(char board[3][3],char XO);
char nextChoice(char board[3][3],char XO);
char randChoice(char board[3][3],char XO);
char smartChoice(char board[3][3],char XO);
char bestMove(char board[3][3],char XO);

int main(int argc, char **argv) {

	printf("Welcome to tic-tac-toe\n");
	player player1 = choosePlayer('X');
	player player2 = choosePlayer('O');
	playGame(player1,player2);
	return 0;
}

player choosePlayer(char XO) {
	char choice;
	printf("Choose player to use the %c token\n",XO);
	printf("   A. Human (you)\n");
	printf("   B. Computer Next Available Algorithm\n");
	printf("   C. Computer Random Choice Algorithm\n");
	printf("   D. Compunter Smart Choice Algorithm\n");
	printf("   E. Computer Never Lose Algorithm\n");
	scanf("Please enter a letter from A,B,C,D, or E : ");
	scanf(" %c",&choice);
	switch(choice) {
		case 'A': return humanChoice;
		case 'B': return nextChoice;
		case 'C': return randChoice;
		case 'D': return smartChoice;
		case 'E': return bestMove;
		default :
			printf("Sorry... those are the only choices currently implemented\n");
			exit(1);
	}
	return NULL;
}
/*===================================================================================*/
char humanChoice(char board[3][3],char XO) {
	char choice=' ';
	while(!isPositionChar(choice)) {
		printf("Where would you like to place an %c? (a-i): ",XO);
		scanf(" %c",&choice);
		if (choice=='q') exit(1);
		if (isPositionChar(choice)) {
			int row=charToRow(choice);
			int col=charToCol(choice);
			if (board[row][col]!=choice) {
				printf("Please chose a position that is not already taken\n");
			}
		} else {
			printf("Please enter the character a,b,c,d,e,f,g,h or i\n");
		}
	}
	return choice;
}
/*===================================================================================*/
char nextChoice(char board[3][3],char XO) {
	char choice;
	char choices[]="abcdefghi"; // sets up array for possible squares
	int i;
	for(i=0;i<8;i++){ // cycles through squares
		choice=choices[i];
		if (isAvail(board,choice)) { // finds next open square and will choose it
			printf("Computer chose '%c' since it is the next available slot.\n", choice);
			return choice;
		}
		else {continue;}
	}
return ' ';
}
/*===================================================================================*/
char randChoice(char board[3][3],char XO) {
	char choices[]="abcdefghi";
	char avail[9];
	int navail=0;
	int i;
	for(i=0;i<8;i++) {
		if (isAvail(board,choices[i])) {
			avail[navail]=choices[i];
			navail++;
		}
	}
	int cnum=rand()%navail;
	printf("Computer chooses random available value %c\n",avail[cnum]);
	return avail[cnum];
}
/*===================================================================================*/
char smartChoice(char board[3][3],char XO) {
	char choices[]="abcdefghi"; // sets up array for possible squares
	int j;
	char win;
	char block;
	for(j=0; j<=7; j++) {  // checks for triples to win
		win = ( trip1MoveWinner((getTriplet(board,j)), XO));
			if (isPositionChar(win) && isAvail(board,	win)) {
				printf("Computer chose '%c' since it is a smart move.\n", win);
				return win;
			}
	}
	for(j=0; j<=7; j++) {  //checks triples of opponent to block
		block = ( trip1MoveWinner((getTriplet(board,j)), opponent(XO)));
			if (isPositionChar(block) && isAvail(board,	block)) {
				printf("Computer chose '%c' since it is a smart move.\n", block);
				return block;
		  }
	}
	if( isAvail(board, choices[0])) {  // checks for available corners
		printf("Computer chose '%c' since it is a smart move.\n", choices[0]);
		return choices[0];
	}
	else if( isAvail(board, choices[2])) {
		printf("Computer chose '%c' since it is a smart move.\n", choices[2]);
		return choices[2];
	}
	else if( isAvail(board, choices[6])) {
		printf("Computer chose '%c' since it is a smart move.\n", choices[6]);
		return choices[6];
	}
	else if( isAvail(board, choices[8])) {
		printf("Computer chose '%c' since it is a smart move.\n", choices[8]);
		return choices[8];
	}
	else if( isAvail(board, choices[4])) { // last one checks for middle square
		printf("Computer chose '%c' since it is a smart move.\n", choices[4]);
		return choices[4];
	}
	return nextChoice(board, XO); // Chooses next Available square
return  ' ';
}
/*===================================================================================*/
char bestMove(char board[3][3],char XO) {
	/*
	char choices[]="abcdefghi"; // sets up array for possible squares
	int j;
	int x;
	int y;
	char win;
	char block;
	for(j=0; j<=7; j++) {  // checks all the triples in rows, columns, diagonals
		win = ( trip1MoveWinner((getTriplet(board,j)), XO));
			if (isPositionChar(win) && isAvail(board,	win)) {
				printf("Computer chose '%c' since it is a smart move.\n", win);
				return win;
			}
	}


	}
	for(x=0; x<3; x++) { // steps through squares
		for(y=0; y<3; y++) {
			if board[x][y]='a'||'b'||'c'||'d'||'e'||'g'||'h'||'i'
				board[x][y]=XO  // try this square if not taken
				int currentscore =
		}
	}
	*/
 }
