/**
*	BOJ
*	No.11050	이항 계수1
*	@author	peter9378
*	@date		2019.07.25
*/
#include <iostream>
#include <algorithm>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	int answer = 1;
	for (int i = 0; i < K; i++)
		answer *= (N-i);
	while (K)
	{
		answer /= K;
		K--;
	}
	cout << answer;

	return 0;
}
