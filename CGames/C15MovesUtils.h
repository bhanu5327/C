int goLeft(Board *board);
int goUp(Board *board);
int goDown(Board *board);
int goRight(Board *board);
void swap(Board *board, int x1, int y1, int x2, int y2);
int isValidInput(char letter);



/*
Take Only Valid Input W,A,S,D,w,a,s,d . If Invalid input is entered ,Take input again . Keep Taking input until its valid
Hint : Use While Loop and isValidInput function
*/
char takeInput()
{
	int d=0; char c;
	while (1)
	{
		scanf("%c", &c);
		d = isValidInput(c);
		if (d == 1)break;
	}
	
	
	/*
	Take input and return it ,Use fflush if scanf is being used .
	Does this function need fflush ? Whats fflush ? Post your observations in the forum ,if fflush is present/not present.
	*/
	return c;
}
/*
Return 1 for Valid Input ie if w,a,s,d,W,A,S,D are entered .
Return 0 for all other inputs
*/
int isValidInput(char letter)
{
	if (letter == 'W' || letter == 'S' || letter == 'A' || letter == 'D' || letter == 'w' || letter == 's' || letter == 'a' || letter == 'd')
		return 1;
	else
		return 0;
}
/*
Process the Given Input .Ie Decide whether to move Left , Right , Up ,or Down based on W,A,S,D,w,a,s,d.
Call goLeft Function if A or a are entered.,similarly do for all valid inputs .
Output :
Returns 1 : If Input is Valid and Move is also Valid .
Returns 0 : If Input if Valid and Move is Invalid .
Returns 0: If Input is invalid ,like other letters are entered or sent through takeInput.
*/
int processInput(Board *board, char inputChar)
{
	int k=0;
	if (inputChar == 'A' || inputChar == 'a')
	{
		k = goLeft(board); 
	}
	if (inputChar == 'D' || inputChar == 'd')
	{
		k = goRight(board); 
	}
	if (inputChar == 'W' || inputChar == 'w')
	{
		k = goUp(board); 
	}
	if (inputChar == 'S' || inputChar == 's')
	{
		k = goDown(board); 
	}
	/*
	Handle the input char inputChar ,which is either w,a,s,d,W,A,S,D for up,left,down and right
	*/
	if (k == 0) return 0;
	else
	return 1;
}

/*
This Method is invoked when a character is taken as input ie User has played his ValidMove ,and you need to proccess that Move .
Steps to be Done :
1)Call ProcessInput
2)Call modifyMoveCountBasedOnProccessInput and also pass Step 1s output
3)Call clearAndRedrawScreen
4)Call printUser
*/
void playMove(Board *board, User *user, char choice){
	//printf("Play move not implemented yet , Remove this printf btw ");
	int k,x1=board->emptyTileRow,y1=board->emptyTileCol,x2=x1,y2=y1;
	k=processInput(board,choice);
	if (k == 1)
	{
		if (choice == 'A' || choice == 'a') y2++;
		else if (choice == 'D' || choice == 'd')y2--;
		else if (choice == 'W' || choice == 'w')x2++;
		else if (choice == 'S' || choice == 's')x2--;
		swap(board, x1, y1, x2, y2);
	}
	modifyMoveCountBasedOnProccessInput(user, k);
	clearAndRedrawScreen(board);
	printUser(user);
}

/*
Move the 0 Tile one position to the left .
Return 1 if the move is possible, 0 other wise .
*/
int goLeft(Board *board)
{
	if(board->emptyTileCol==3)
	return 0;
	else return 1;
}

/*
Move the 0 Tile one position to the Right.
Return 1 if the move is possible, 0 other wise .
*/
int goRight(Board *board)
{
	if (board->emptyTileCol == 0)
		return 0;
	else return 1;
}

/*
Move the 0 Tile one position to the UP .
Return 1 if the move is possible, 0 other wise .
*/
int goUp(Board *board){
	if (board->emptyTileRow == 3)
		return 0;
	else return 1;
}

/*
Move the 0 Tile one position to the Down .
Return 1 if the move is possible, 0 other wise .
*/
int goDown(Board *board){
	if (board->emptyTileRow == 0)
		return 0;
	else return 1;
}


/*
You can use this Helper SWAP Function which can remove lots of extra Code from above functions .
*/
void swap(Board *board, int x1, int y1, int x2, int y2)
{
	int t,l;
	l = board->table[x2][y2];
	t = board->table[x1][y1];
	board->table[x1][y1] = board->table[x2][y2];
	board->table[x2][y2] = t;
	board->emptyTileRow = x2;
	board->emptyTileCol = y2;
}