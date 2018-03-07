#include <stdio.h>
#include <assert.h>
#include "ttt.h"

void playGame(player player1, player player2) {
	char board[3][3]={{'a','b','c'},{'d','e','f'},{'g','h','i'}};
	int turn;
	char token;
	char choice;

	for(turn=0; turn<10; turn++) {
		drawBoard(board);
		char win=winner(board);
		if (win!=' ') {
			printf("Congratulations... %c won!\n",win);
			return;
		}
		if (isTie(board)) {
			printf("Sorry... it's a tie. Better luck next time.\n");
			return;
		}
		if (turn%2==0) {
			token='X';
			choice=player1(board,'X');
		} else {
			token='O';
			choice=player2(board,'O');
		}
		if (!isPositionChar(choice)) break;
		assert(isAvail(board,choice));
		int row=charToRow(choice);
		int col=charToCol(choice);
		board[row][col]=token;
	}
	assert(0=="Should never get here");
}

void drawBoard(char board[3][3]) {
	printf("  %c | %c | %c\n",board[0][0],board[0][1],board[0][2]);
	printf(" ---+---+---\n");
	printf("  %c | %c | %c\n",board[1][0],board[1][1],board[1][2]);
	printf(" ---+---+---\n");
	printf("  %c | %c | %c\n",board[2][0],board[2][1],board[2][2]);
	printf("\n");
}


char winner(char board[3][3]) {
	int t;
	for(t=0;t<8;t++) {
		char tw=tripletWinner(getTriplet(board,t));
		if (tw!=' ') return tw;
	}
	return ' ';
}

int isTie(char board[3][3]) {
	 int t;
	 for(t=0;t<8;t++) {
		 if (!isTripTie(getTriplet(board,t))) return 0;
	 }
	 return 1;
 }

 char * getTriplet(char board[3][3],int tnum) {
 	static char triplet[3];
 	switch(tnum) {
 		case 0: 	triplet[0]=board[0][0];
 							triplet[1]=board[0][1];
 							triplet[2]=board[0][2];
 							break;
 		case 1: 	triplet[0]=board[1][0];
 							triplet[1]=board[1][1];
 							triplet[2]=board[1][2];
 							break;
 		case 2: 	triplet[0]=board[2][0];
 							triplet[1]=board[2][1];
 							triplet[2]=board[2][2];
 							break;
 		case 3: 	triplet[0]=board[0][0];
 							triplet[1]=board[1][0];
 							triplet[2]=board[2][0];
 							break;
 		case 4: 	triplet[0]=board[0][1];
 							triplet[1]=board[1][1];
 							triplet[2]=board[2][1];
 							break;
 		case 5: 	triplet[0]=board[0][2];
 							triplet[1]=board[1][2];
 							triplet[2]=board[2][2];
 							break;
 		case 6: 	triplet[0]=board[0][0];
 							triplet[1]=board[1][1];
 							triplet[2]=board[2][2];
 							break;
 		case 7: 	triplet[0]=board[0][2];
 							triplet[1]=board[1][1];
 							triplet[2]=board[2][0];
 							break;
 		 default:
 		 					assert(0=="Invalid triplet number in getTriplet");
 	 }
 	 return triplet;
 }

char tripletWinner(char trip[3]) {
	 char w=trip[0];
	 if (w==trip[1] && w==trip[2]) return w;
	 return ' ';
 }

 int isTripTie(char trip[3]) {
 	 /* Triplet is a tie if it has both X and O */
 	 if (trip[0]=='X' || trip[1]=='X' || trip[2]=='X') {
 		 if (trip[0]=='O' || trip[1]=='O' || trip[2]=='O') return 1;
 	 }
 	 return 0;
 }

 char trip1MoveWinner(char trip[3],char XO) {
 	if (trip[0]==XO && trip[1]==XO && !isXO(trip[2])) return trip[2];
 	if (trip[0]==XO && trip[2]==XO && !isXO(trip[1])) return trip[1];
 	if (trip[1]==XO && trip[2]==XO && !isXO(trip[0])) return trip[0];
 	return ' ';
}

int isAvail(char board[3][3],char pos) {
	if (!isPositionChar(pos)) return 0;
	int row=charToRow(pos);
	int col=charToCol(pos);
	return (board[row][col]==pos);
}

int charToRow(char pos) {
	switch(pos) {
		case 'a' :
		case 'b' :
		case 'c' : return 0;
		case 'd' :
		case 'e' :
		case 'f' : return 1;
		case 'g' :
		case 'h' :
		case 'i' : return 2;
		default:
			assert(0=="Invalid argument to charToRow");
	}
	return -1;
}

int charToCol(char pos) {
	switch(pos) {
		case 'a' :
		case 'd' :
		case 'g' : return 0;
		case 'b' :
		case 'e' :
		case 'h' : return 1;
		case 'c' :
		case 'f' :
		case 'i' : return 2;
		default:
			assert(0=="Invalid argument to charToCol");
	}
	return -1;
}

int isPositionChar(char pos) {
	switch(pos) {
			case 'a' :
			case 'd' :
			case 'g' :
			case 'b' :
			case 'e' :
			case 'h' :
			case 'c' :
			case 'f' :
			case 'i' : return 1;
	}
	return 0;
}

char opponent(char XO) {
	if (XO=='X') return 'O';
	if (XO=='O') return 'X';
	assert(0=="Invalid argument to the opponent function");
	return ' ';
}

int isXO(char XO) {
	if (XO=='X') return 1;
	if (XO=='O') return 1;
	return 0;
}
