/**
*	BOJ
*	No.15897	잘못 구현한 에라토스테네스의 체
*	@author	peter9378
*	@date		2019.06.22
*/
#include <iostream>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N;
	cin >> N;

	long long count = 0;
	for (int i = N; i != 0; i = (N - 1) / ((N - 1) / i + 1))
		count += ((N - 1) / i + 1) * (i - ((N - 1) / ((N - 1) / i + 1)));
	
	cout << count;

	return 0;
}