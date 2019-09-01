/**
*	BOJ
*	No.1063	킹
*	@author	peter9378
*	@date		2019.09.01
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[9][9];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	int N;
	cin >> a >> b >> N;

	int x1 = a[0] - 64;
	int y1 = a[1] - 48;
	int x2 = b[0] - 64;
	int y2 = b[1] - 48;

	string command;
	while (N--)
	{
		cin >> command;

		if (command.length() == 1)
		{
			int i = 0;

			switch (command[i])
			{
			case 'R':
				if (x1 < 9)
				{
					x1++;
					if (x1 == 9 && x2 == 9)
						x1--;
					else if (x1 == x2 && y1 == y2)
					{
						if (x2 == 8)
							x1--;
						else
							x2++;
					}
					else if (x1 == 9)
						x1--;
				}
				break;
			case 'L':
				if (x1 > 0)
				{
					x1--;
					if (x1 == 0 && x1 == 0)
						x1++;
					else if (x1 == x2 && y1 == y2)
					{
						if (x2 == 1)
							x1++;
						else
							x2--;
					}
					else if (x1 == 0)
						x1++;
				}
				break;
			case 'B':
				if (y1 > 0)
				{
					y1--;
					if (y1 == 0 && y2 == 0)
						y1++;
					else if (x1 == x2 && y1 == y2)
					{
						if (y2 == 1)
							y1++;
						else
							y2--;
					}
					else if (y1 == 0)
						y1++;
				}
				break;
			case 'T':
				if (y1 < 9)
				{
					y1++;
					if (y1 == 9 && y2 == 9)
						y1--;
					else if (x1 == x2 && y1 == y2)
					{
						if (y2 == 8)
							y1--;
						else
							y2++;
					}
					else if (y1 == 9)
						y1--;
				}
				break;
			}
		}
		else
		{
			int tempx = x1;
			int tempy = y1;
			for (int i = 0; i < 2; i++)
			{
				switch (command[i])
				{
				case 'R':
					x1++;
					break;
				case 'L':
					x1--;
					break;
				case 'B':
					y1--;
					break;
				case 'T':
					y1++;
					break;
				}
			}
			if (x1 < 1 || x1>8 || y1 < 1 || y1>8)
			{
				x1 = tempx;
				y1 = tempy;
			}
			else if (x1 == x2 && y1 == y2 && x1 < 9 && y1 < 9 && x1>0 && y1>0)
			{
				int temptempx = x2;
				int temptempy = y2;
				for (int i = 0; i < 2; i++)
				{
					switch (command[i])
					{
					case 'R':
						x2++;
						break;
					case 'L':
						x2--;
						break;
					case 'B':
						y2--;
						break;
					case 'T':
						y2++;
						break;
					}
				}
				if (x2 == 0 || x2 == 9 || y2 == 0 || y2 == 9)
				{
					x1 = tempx;
					y1 = tempy;
					x2 = temptempx;
					y2 = temptempy;
				}
			}
			else if (x1 != x2 && y1 != y2 && x1 < 9 && y1 < 9 && x1 > 0 && y1 > 0)
				continue;
		}
	}

	cout << (char)(x1 + 64) << y1 << "\n" << (char)(x2 + 64) << y2;

	return 0;
}