/**
*	baekjoon_stepbystep
*	No. 11653	소인수분해
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

	for (int i = 2; i*i <= N; i++)
	{
		if (N%i == 0)
		{
			cout << i << "\n";
			N /= i;
			i--;
		}
	}

	if (N > 1)
		cout << N;

	return 0;
}