/**
*	BOJ
*	No.15947	¾Æ±â ¼®È¯ ¶Ñ·ç·ç ¶Ñ·ç
*	@author	peter9378
*	@date		2019.12.08
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	N--;

	int loop = N / 14;
	int index = N % 14;

	switch (index)
	{
	case 0:
		cout << "baby";
		break;
	case 1:
		cout << "sukhwan";
		break;
	case 2:
		if (loop < 3)
		{
			cout << "tu";
			for (int i = -2; i < loop; i++)
				cout << "ru";
		}
		else
			cout << "tu+ru*" << loop + 2;
		break;
	case 3:
		if (loop < 4)
		{
			cout << "tu";
			for (int i = -1; i < loop; i++)
				cout << "ru";
		}
		else
			cout << "tu+ru*" << loop + 1;
		break;
	case 4:
		cout << "very";
		break;
	case 5:
		cout << "cute";
		break;
	case 6:
		if (loop < 3)
		{
			cout << "tu";
			for (int i = -2; i < loop; i++)
				cout << "ru";
		}
		else
			cout << "tu+ru*" << loop + 2;
		break;
	case 7:
		if (loop < 4)
		{
			cout << "tu";
			for (int i = -1; i < loop; i++)
				cout << "ru";
		}
		else
			cout << "tu+ru*" << loop + 1;
		break;
	case 8:
		cout << "in";
		break;
	case 9:
		cout << "bed";
		break;
	case 10:
		if (loop < 3)
		{
			cout << "tu";
			for (int i = -2; i < loop; i++)
				cout << "ru";
		}
		else
			cout << "tu+ru*" << loop + 2;
		break;
	case 11:
		if (loop < 4)
		{
			cout << "tu";
			for (int i = -1; i < loop; i++)
				cout << "ru";
		}
		else
			cout << "tu+ru*" << loop + 1;
		break;
	case 12:
		cout << "baby";
		break;
	case 13:
		cout << "sukhwan";
		break;
	}

	return 0;
}