/**
*	baekjoon_stepbystep
*	No. 10872	팩토리얼
*	@author	peter9378
*	@date		2018.05.10
*/
#include <iostream>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long N;
	cin >> N;

	long long result = 1;
	for (int i = 2; i <= N; i++)
		result *= i;

	cout << result;

	return 0;
}