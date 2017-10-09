#include <iostream>
#include <conio.h>

using namespace std;

struct _tagPoint
{
	int x;
	int y;
};

typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;

void SetMaze(char Maze[21][21], PPOINT pPlayerPos, PPOINT pStartPos, PPOINT pEndPos)
{
	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 19;
	pEndPos->y = 19;

	pPlayerPos->x = 0;
	pPlayerPos->y = 0;

	strcpy_s(Maze[0],  "21100000000000000000");
	strcpy_s(Maze[1],  "00111111111111110000");
	strcpy_s(Maze[2],  "00000000000000011000");
	strcpy_s(Maze[3],  "00000000000000001000");
	strcpy_s(Maze[4],  "00111111111111111000");
	strcpy_s(Maze[5],  "00100000010000000000");
	strcpy_s(Maze[6],  "00100000011100001000");
	strcpy_s(Maze[7],  "01110000000100011000");
	strcpy_s(Maze[8],  "01010000000111110000");
	strcpy_s(Maze[9],  "01000000000000000000");
	strcpy_s(Maze[10], "01111100000000000000");
	strcpy_s(Maze[11], "00000111111111110000");
	strcpy_s(Maze[12], "00010000000100011111");
	strcpy_s(Maze[13], "00010001000100000000");
	strcpy_s(Maze[14], "00111111111100011110");
	strcpy_s(Maze[15], "00100000000000001000");
	strcpy_s(Maze[16], "00111111111111111000");
	strcpy_s(Maze[17], "00000000000001000000");
	strcpy_s(Maze[18], "00000000000001000000");
	strcpy_s(Maze[19], "00000000000001111113");
}

void Output(char Maze[21][21], PPOINT pPlayerPos)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (pPlayerPos->x == i && pPlayerPos->y == j)
				cout << "¡Ø";
			else if (Maze[i][j] == '0')
				cout << "¡á";
			else if (Maze[i][j] == '1')
				cout << "  ";
			else if (Maze[i][j] == '2')
				cout << "¡Ú";
			else if (Maze[i][j] == '3')
				cout << "¡Ý";
		}
		cout << endl;
	}
}

void MoveLeft(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y != 0)
	{
		if(Maze[pPlayerPos->x][pPlayerPos->y-1] != '0')
			pPlayerPos->y--;
	}
}

void MoveRight(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y != 19)
	{
		if (Maze[pPlayerPos->x][pPlayerPos->y+1] != '0')
			pPlayerPos->y++;
	}
}

void MoveUp(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x != 0)
	{
		if (Maze[pPlayerPos->x-1][pPlayerPos->y] != '0')
			pPlayerPos->x--;
	}
}

void MoveDown(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x != 19)
	{
		if (Maze[pPlayerPos->x+1][pPlayerPos->y] != '0')
			pPlayerPos->x++;
	}
}


void MovePlayer(char Maze[21][21], PPOINT pPlayerPos, char cInput)
{
	switch (cInput)
	{
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayerPos);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayerPos);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayerPos);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayerPos);
		break;
	}
}

int main()
{
	char strMaze[21][21];

	POINT tPlayerPos;
	POINT tStartPos;
	POINT tEndPos;

	SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos);

	while (1)
	{
		system("cls");
		Output(strMaze, &tPlayerPos);

		if (tPlayerPos.x == tEndPos.x && tPlayerPos.y == tEndPos.y)
		{
			cout << "µµÂøÇß½À´Ï´Ù." << endl;
			break;
		}

		cout << "t : ÆøÅº ¼³Ä¡ u : ÆøÅº ÅÍÆ®¸®±â" << endl;
		cout << "w : À§ s : ¾Æ·¡ a : ¿ÞÂÊ d : ¿À¸¥ÂÊ q : Á¾·á" << endl;
		cout << "ÀÔ·Â : ";
		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
			break;
		else if(cInput)
		MovePlayer(strMaze, &tPlayerPos, cInput);
	}

	return 0;
}