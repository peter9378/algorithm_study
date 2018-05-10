/**
*	baekjoon_stepbystep
*	No. 1676	팩토리얼 0의 개수
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
	
	int N;
	cin >> N;

	int answer = 0;
	while (N)
	{
		N /= 5;
		answer += N;
	}

	cout << answer;

	return 0;
}