#include <iostream>
#include <time.h>
#include <conio.h>
#include "shuffle.h"
using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};
	int star_location = 24;

	for(int i = 0; i < 24; i++)
	{
		iNumber[i] = i + 1;
	}
	iNumber[24] = INT_MAX;
	shuffle(iNumber, 24);

	while (1)
	{
		system("cls");
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (iNumber[i * 5 + j] != INT_MAX)
					cout << iNumber[i * 5 + j] << "\t";
				else
					cout << "*\t";

			}
			cout << endl;
		}

		cout << "w : 위 s : 아래 a : 왼쪽 d : 오른쪽 q : 종료" << endl << " >> ";
		char cInput = _getch();
		if (cInput == 'q' || cInput == 'Q')
		{
			cout << endl << "게임을 종료합니다" << endl;
			break;
		}

		switch (cInput)
		{
		case 'w' :
		case 'W' :
			if (star_location/ 5 != 0)
			{
				int swap_location;
				int temp_value;
				swap_location = star_location - 5;
				
				temp_value = iNumber[star_location];
				iNumber[star_location] = iNumber[swap_location];
				iNumber[swap_location] = temp_value;
				star_location = swap_location;
			}
			break;
		case 's' :
		case 'S' :
			if (star_location / 5 != 4)
			{
				int swap_location;
				int temp_value;
				swap_location = star_location + 5;

				temp_value = iNumber[star_location];
				iNumber[star_location] = iNumber[swap_location];
				iNumber[swap_location] = temp_value;
				star_location = swap_location;
			}
			break;
		case 'a' :
		case 'A' :
			if (star_location % 5 != 0)
			{
				int swap_location;
				int temp_value;
				swap_location = star_location - 1;

				temp_value = iNumber[star_location];
				iNumber[star_location] = iNumber[swap_location];
				iNumber[swap_location] = temp_value;
				star_location = swap_location;
			}
			break;
		case 'd' :
		case 'D' :
			if (star_location % 5 != 4)
			{
				int swap_location;
				int temp_value;
				swap_location = star_location +1;

				temp_value = iNumber[star_location];
				iNumber[star_location] = iNumber[swap_location];
				iNumber[swap_location] = temp_value;
				star_location = swap_location;
			}
			break;
		default:
			break;
		}
		int game_clear = 0;
		for (int i = 0; i < 22; i++)
			if (iNumber[i] == i+1)
				game_clear++;
		if (game_clear == 24)
		{
			cout << "Congratuation!!" << endl;
			break;
		}
	}

	return 0;
}