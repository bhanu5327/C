/*
This struct denotes the move played by user, X means the x cordinate and Y means y cordinate.
*/
typedef struct ReversiMove {
	int x, y;
}ReversiMove;

/*
Create a ReversiMove struct (malloc/calloc etc) and return it.
Assign parameters x and y to its fields.
*/
ReversiMove *createMove(int x, int y) {
	ReversiMove *reverse = (ReversiMove *)malloc(sizeof(ReversiMove));
	reverse->x = x;
	reverse->y = y;
	return reverse;
}

/*
	Take Only Valid Input x, y two integers . If Invalid input is entered ,Take input again . Keep Taking input until its valid
	Hint : Use While Loop and isValidInput function
	Cordinates are 1 indexed. Ie first row/column is denoted by 1 while giving input.
*/

ReversiMove *inputMove(ReversiGame *game) {
	
	int x, y;
	scanf("%d %d", &x, &y);
	ReversiMove * temp = createMove(x, y);
	//playMove(game, temp);
	

	return temp;
}


/*
	To check the validity of coordinate on the board 
*/

int isvalidCoordinate(ReversiGame *game, int x, int y) {
	x--; y--;
	if (y < game->rows&&x >= 0 && x < game->cols&&y >= 0)
	{
		if (game->board[y][x] == ' ')
		return 1;
	}
	else
	return 0;
}

/*
Check if the move can be placed, if its going to make a valid capture to the opponent coins
*/

int isValidMove(ReversiGame *game, ReversiMove *move)
{
	int a = move->x, b = move->y; int i, j, k = 0; int z[16]; int v = 0, h = 0, p; char u;
	p = isvalidCoordinate(game, a, b);
	if (p == 1)
	{
		for (i = a - 1; i <= a + 1; i++)
		{
			for (j = b - 1; j <= b + 1; j++)
			{
				if (i == a&&j == b)
				{
				}
				else
				{
					z[k++] = i; z[k++] = j;
				}
			}
		}
		if (game->turn == 1) u = 'w';
		else u = 'b';
		for (i = 0; i < 16;)
		{
			int s = z[i], t = z[i + 1], count = 0; v++; s--; t--;
			while (t <game->rows&&s <game->cols&&s >= 0 && t >= 0)
			{
				if (game->board[t][s] == ' ') break;
				else
				{
					if (game->board[t][s] != u)
					{
						count++;
						if (v == 1){ s--; t--; }
						else if (v == 2){ s--; }
						else if (v == 3){ s--; t++; }
						else if (v == 4){ t--; }
						else if (v == 5){ t++; }
						else if (v == 6){ s++; t--; }
						else if (v == 7){ s++; }
						else if (v == 8){ s++; t++; }
					}
					else
					{
						if (count > 0)
						{
							h = 1;
							break;
						}
						else break;
					}
				}
			}
			if (h == 1) break;
			i = i + 2;
		}

		if (h == 1) return 1;
		else
			return 0;
	}
	else return 0;
}

/*
Check if the player can move , if the player is not able to move, he looses the turn
and the opponent gets the chance to play.
If both players are not able to make a move, then the game ends.
*/

int hasMove(ReversiGame *game){
	int d=0;
	for (int i = 0; i < game->rows; i++)
	{
		for (int j = 0; j < game->cols; j++)
		{
			if (game->board[i][j] == ' ')
			{
				ReversiMove*temp=createMove(j+1, i+1);
				 d=isValidMove(game, temp);
				if (d == 1) break;
			}
		}
		if (d == 1) break;
	}
	if (d == 1)
	{
		//game->NumberofMoves++;
		return 1;
	}
	/*else
	{
		if (game->turn == 1)
			game->turn = -1;
		else
		game->turn = 1;
	}
	for (int i = 0; i < game->rows; i++)
	{
		for (int j = 0; j < game->cols; j++)
		{
			if (game->board[i][j] == ' ')
			{
				ReversiMove*temp = createMove(i, j);
				d = isValidMove(game, temp);
				if (d == 1) break;
			}
		}
		if (d == 1) break;
	}
	if (d == 1) return 1;*/
	else
	return 0;
}

/*
Increment the number of moves in ReversiGame struct.
*/
void incrementMoves(ReversiGame *game) 
{
	game->NumberofMoves++;
}

/*
Toggle the turn in Reversi Game.
This function is to be called when you want to change the turn.
*/
void modifyTurn(ReversiGame *game) {
	if (game->turn == 1) game->turn=-1;
	else game->turn = 1;
}

/*
End Reversi Game.
Populate game->winner field accordingly with who won. 1 for white, -1 for black.
This function is to be called when the game is ended.
*/
void endGame(ReversiGame *game) {
	if (game->whiteCount > game->blackCount)
	{
		game->winner = 1;
	}
	else if (game->whiteCount < game->blackCount){ game->winner = -1; }
	else
	{
		game->winner = 0;
	}
	game->state = 1;
}

/*
	Wrapper function you will call only modify to increment moves and modify the turn.
*/

void modify(ReversiGame *game) {
	incrementMoves(game);
	modifyTurn(game);
}


/*
	This function performs move action on the board
	Note : call validity check performs using above functions before making a move
	returns :
	true on move sucess
	false if move is invalid
*/

bool playMove(ReversiGame *game, ReversiMove *move) {
	int d, m, n, h = 0; char f;
	f = game->turn;
	d = isValidMove(game, move);
	if (d == 1)
	{
		int a = move->x, b = move->y; int i, j, k = 0; int z[16]; int v = 0, h = 0, p; char u;
	
		for (i = a - 1; i <= a + 1; i++)
		{
			for (j = b - 1; j <= b + 1; j++)
			{
				if (i == a&&j == b)
				{
				}
				else
				{
					z[k++] = i; z[k++] = j;
				}
			}
		}
		if (game->turn == 1)
			u = 'w';
		else u = 'b';
		
		for (i = 0; i < 16;)
		{
			int s = z[i], t = z[i + 1], count = 0; v++; int r = 0; s--; t--;
			while (t <game->rows&&s <game->cols&&s >= 0 && t >= 0)
			{
				if (game->board[t][s] == ' ') break;
				else
				{
					if (game->board[t][s] != u)
					{
						count++;
						if (v == 1){ s--; t--; }
						else if (v == 2){ s--; }
						else if (v == 3){ s--; t++; }
						else if (v == 4){ t--; }
						else if (v == 5){ t++; }
						else if (v == 6){ s++; t--; }
						else if (v == 7){ s++; }
						else if (v == 8){ s++; t++; }
					}
					else
					{
						if (count > 0)
						{
							m = a-1; n = b-1; h = 1; r++;
							while (m != s||n != t)
							{
								game->board[n][m] = u;
								/*if (game->turn == 1)
								{
									if (m == a-1&&n == b-1&&r==1)
									{
										game->whiteCount++;
									}
									else if (m == a - 1 && n == b - 1){}
									else{
										game->whiteCount++; game->blackCount--;
									}
								}
								else
								{
									if (m == a-1&&n == b-1&&r==1)
									{
										game->blackCount++;
									}
									else if (m == a - 1 && n == b - 1){}
									else{
										game->blackCount++; game->whiteCount--;
									}
								}*/
								
								if (v == 1){ m--; n--; }
								else if (v == 2){ m--; }
								else if (v == 3){ m--; n++; }
								else if (v == 4){ n--; }
								else if (v == 5){ n++; }
								else if (v == 6){ m++; n--; }
								else if (v == 7){ m++; }
								else if (v == 8){ m++; n++; }

							}
							
						}
						break;
					}
					
				}
			}
			
			i = i + 2;
		}
		game->whiteCount = 0; game->blackCount = 0;
		for (int i = 0; i < game->rows; i++)
		{
			for (int j = 0; j < game->cols; j++)
			{
				if (game->board[i][j] == 'w'){ game->whiteCount++; }
				else if (game->board[i][j] == 'b'){ game->blackCount++; }
			}
		}
	modify(game);
	int g=hasMove(game);
	if (g == 0){ modifyTurn(game); }
		return true;

	}
	return false;
}


void printWinner(ReversiGame *game) {
	/*
	Sample output :
	Result Praveen has won. / Game is Drawn.
	*/

}