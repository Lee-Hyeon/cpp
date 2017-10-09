#include <iostream>
#include <time.h>

using namespace std;

// 야구게임 - 3개 숫자 맞추기

int main()
{
	srand((unsigned int)time(0));

	int answer[3];
	for (int i = 0; i < 3; i++)
		answer[i] = rand()%10;
	int user[3];
	int strike, ball;
	while (1)
	{
		cout << "input 3 numbers" << endl << "input : ";
		for (int i = 0; i < 3; i++)
			cin >> user[i];
		strike = ball = 0;
		for (int i = 0; i < 3; i++)
			if (answer[i] == user[i])
				strike++;
		if (answer[0] == user[1] || answer[0] == user[2])
			ball++;
		if (answer[1] == user[0] || answer[1] == user[2])
			ball++;
		if (answer[2] == user[0] || answer[2] == user[1])
			ball++;

		if (strike == ball && ball == 0)
			cout << "Out" << endl;
		else if (strike == 3)
		{
			cout << "Congratuation!!!" << endl;
			break;
		}
		else
			cout << strike << "strike " << ball << "ball" << endl;
	}
}