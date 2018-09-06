/**
*	baekjoon online judge
*	No. 2490	¿∑≥Ó¿Ã
*	@author	peter9378
*	@date		2018.09.06
*/
#include <iostream>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 3;

	for (int test_case = 0; test_case < T; test_case++)
	{
		int sum = 0, temp;
		for (int i = 0; i < 4; i++)
		{
			cin >> temp;
			sum += temp;
		}

		switch (sum)
		{
		case 0:
			cout << "D\n";
			break;
		case 1:
			cout << "C\n";
			break;
		case 2:
			cout << "B\n";
			break;
		case 3:
			cout << "A\n";
			break;
		case 4:
			cout << "E\n";
			break;
		}
	}

	return 0;
}