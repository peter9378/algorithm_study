/**
*	baekjoon online judge
*	No. 1212	8진수 2진수
*	@author	peter9378
*	@date		2018.05.06
*/
#include <iostream>
#include <string.h>
using namespace std;

char arr[333335];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> arr;
	int length = strlen(arr);

	if (length == 1)
	{
		cout << arr[0];
		return 0;
	}

	for (int i = 0; i < length; i++)
	{
		int num = arr[i] - '0';

		if (i == 0 && num > 0 && num <= 3)
		{
			switch (num)
			{
			case 1:
				cout << 1;
				break;
			case 2:
				cout << 10;
				break;
			case 3:
				cout << 11;
				break;
			}
		}
		else
		{
			switch (num)
			{
			case 0:
				cout << "000";
				break;
			case 1:
				cout << "001";
				break;
			case 2:
				cout << "010";
				break;
			case 3:
				cout << "011";
				break;
			case 4:
				cout << "100";
				break;
			case 5:
				cout << "101";
				break;
			case 6:
				cout << "110";
				break;
			case 7:
				cout << "111";
				break;
			}
		}
	}

	return 0;
}