/**
*	BOJ
*	No.2576	홀수
*	@author	peter9378
*	@date		2019.09.16
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int mini = 101, sum = 0;
	for (int i = 0; i < 7; i++)
	{
		int temp;
		cin >> temp;
		if (temp % 2)
		{
			if (temp < mini)
				mini = temp;
			sum += temp;
		}
	}

	if (sum == 0)
		cout << -1;
	else
		cout << sum << "\n" << mini;

	return 0;
}