/**
*	Code Forces
*	#570 A.	Nearest Interesting Number
*	@author	peter9378
*	@date		2019.06.27
*/
#include <iostream>
#include <algorithm>
using namespace std;

int sum_digit(int target)
{
	int sum = 0;
	while (target)
	{
		sum += target % 10;
		target /= 10;
	}
	return sum;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	while (sum_digit(N) % 4 != 0)
	{
		N++;
	}

	cout << N;
	return 0;
}