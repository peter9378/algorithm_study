/**
*	BOJ
*	No.2986	파스칼
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

	// find biggest divisor of N
	int answer = 1;
	for (int i = 2; i*i <= N; i++)
	{
		if (N%i == 0)
		{
			answer = N / i;
			break;
		}
	}
	
	// print answer
	cout << N - answer;

	return 0;
}