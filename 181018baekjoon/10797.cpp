/**
*	baekjoon online judge
*	No. 10797	10ºÎÁ¦
*	@author	peter9378
*	@date		2018.10.18
*/
#include <iostream>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int day;
	cin >> day;

	int car_num, result = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> car_num;
		if (car_num == day)
			result++;
	}

	cout << result;

	return 0;
}