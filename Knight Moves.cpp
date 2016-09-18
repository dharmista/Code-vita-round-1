#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//IP : 3k4/8/8/8/8/6b1/5r2/K6N w
//IP : 2k1b3/6n1/n7/5R2/8/8/84K3 b
//IP : 3k4/8/8/8/8/1K4R1/5R2/7N w
/*
|       turns:
|           1 -> black   Small
|           0 -> white   Capital
*/

bool can_kill(char targ, char src){
	if ('a' <= src && src <= 'z'){
		if ('A' <= targ && targ <= 'Z')
			return true;
	}
	else if ('A' <= src && src <= 'Z'){
		if ('a' <= targ && targ <= 'z')
			return true;
	}
	return false;
}

int count = 0;

void print_one(char board[8][8], int x, int y, int x1, int y1, char check){
	char * extra;
	if (count == 0)
		extra = "";
	else extra = " ";
	if (board[x1][y1] == 0 || can_kill(board[x1][y1], check)){
		if (x1 >= 0 && y1 >= 0 && x1 < 8 && y1 < 8){
			printf("%s%c%d%c%d,", extra, y + 'a', 8 - x, 'a' + y1, 8 - x1);
			count++;
		}
	}
}

void knight_moves(char board[8][8], int x, int y, bool turn){
	char check = board[x][y];
	print_one(board, x, y, x - 2, y - 1, check);
	print_one(board, x, y, x - 1, y - 2, check);
	print_one(board, x, y, x + 1, y - 2, check);
	print_one(board, x, y, x + 2, y - 1, check);
	print_one(board, x, y, x - 2, y + 1, check);
	print_one(board, x, y, x - 1, y + 2, check);
	print_one(board, x, y, x + 1, y + 2, check);
	print_one(board, x, y, x + 2, y + 1, check);
}

int main(){
	char board[8][8];
	char query[100];
	strcpy(query, "2k1b3/6n1/n7/5R2/8/8/8/4K3 b");
	int pos = 0; bool turn;
	//Parsing
	for (int i = 0; i<8; i++){
		int j = 0;
		while (query[pos] != '/' && query[pos] != ' '){
			if ('0' <= query[pos] && query[pos] <= '9'){
				int targ = query[pos] - '0';
				for (int k = j; k< j + targ; k++){
					board[i][k] = 0;
				}
				j = j + targ;
			}
			else{
				board[i][j++] = query[pos];
			}
			pos++;
		}
		pos++;
	}
	if (query[pos] == 'w')
		turn = 0;
	else
		turn = 1;
	char piece = 'n' - !turn*('a' - 'A');
	printf("[");
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (board[i][j] == piece){
				knight_moves(board, i, j, turn);
			}
		}
	}
	if (count != 0)
		printf("\b]");
	else
		printf("]");
	return 0;
}
