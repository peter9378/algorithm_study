/**
*	BOJ
*	No.16504	종이접기
*	@author	peter9378
*	@date		2019.07.04
*/
#include <iostream>
#include <algorithm>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N;
	cin >> N;

	long long int answer = 0;
	for (int i = 0; i < N*N; i++)
	{
		int temp;
		cin >> temp;

		answer += temp;
	}

	cout << answer;

	return 0;
}