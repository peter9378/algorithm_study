/**
*	SW Expert Academy
*	No. 1824 혁진이의 프로그램 검증
*	@author	peter9378
*	@date		2018.03.28
*/
#include <iostream>
#include <string>
using namespace std;

char input[20][20];
int now_direction;
enum direction {LEFT, RIGHT, UP, DOWN};
int memory;
int probability;
int x, y, R, C;

void go_left()
{
	if (y == 0)
		y = C - 1;
	else
		y--;
	return;
}

void go_right()
{
	if (y == C - 1)
		y = 0;
	else
		y++;
	return;
}

void go_up()
{
	if (x == 0)
		x = R - 1;
	else
		x--;
	return;
}

void go_down()
{
	if (x == R - 1)
		x = 0;
	else
		x++;
	return;
}

int process(char command)
{
	switch (command)
	{
	case '<':
		now_direction = LEFT;
		break;
	case '>':
		now_direction = RIGHT;
		break;
	case '^':
		now_direction = UP;
		break;
	case 'v':
		now_direction = DOWN;
		break;
	case '_':
		if (memory)
			now_direction = LEFT;
		else
			now_direction = RIGHT;
		break;
	case '|':
		if (memory)
			now_direction = UP;
		else
			now_direction = DOWN;
		break;
	case '?':
		if (probability % 4 == 1)
			now_direction = LEFT;
		else if (probability % 4 == 2)
			now_direction = RIGHT;
		else if (probability % 4 == 2)
			now_direction = UP;
		else
			now_direction = DOWN;
		probability++;
		break;
	case '.':
		return 1;
	case '@':
		return 0;
	case '+':
		if (memory == 15)
			memory = 0;
		else
			memory++;
		break;
	case '-':
		if (memory)
			memory--;
		else
			memory = 15;
		break;
	default:
		memory = command - 48;
		break;
	}
	return 1;
}

void initialize()
{
	now_direction = 1;
	memory = 0;
	x = 0;
	y = 0;
	return;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	probability = 0;
	int T;
	cin >> T;

	// 테스트 케이스 루프
	for (int test_case = 1; test_case < 11; test_case++)
	{
		initialize();
		cin >> R >> C;

		string str;
		for (int i = 0; i < R; i++)
		{
			cin >> str;
			for (int j = 0; j < C; j++)
				input[i][j] = str[j];
		}

		int count = 0;
		while (1) 
		{
			int result = process(input[x][y]);
			if (count>R*C*100)
			{
				cout << "#" << test_case << " NO\n";
				break;
			}
			else if (result == 0)
			{
				cout << "#" << test_case << " YES\n";
				break;
			}
			else
			{
				switch (now_direction)
				{
				case 0:
					go_left();
					break;
				case 1:
					go_right();
					break;
				case 2:
					go_up();
					break;
				case 3:
					go_down();
					break;
				}
			}
			count++;
		}
	}
	return 0;
}