/**
*	baekjoon online judge
*	No. 13458	시험 감독
*	@author	peter9378
*	@date		2019.03.04
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int dp[1000001] = { 0 };

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, A, B, C;
	long long count = 0;
	long long answer = 0;

	// input variables
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		v.push_back(A);
	}

	cin >> B >> C;
	for (int i = 0; i < N; i++)
	{
		int student = v[i];

		// if data is already exist
		if (dp[student]) 
			answer += dp[student];
		else // or not
		{
			// remove supervisor
			v[i] -= B;
			count++;

			// remove subvisor
			if (v[i] > 0) 
				count += v[i] / C;
			if (v[i] % C > 0) 
				count++;
			answer += count;
			dp[student] = count;
			count = 0;
		}
	}

	cout << answer;
	return 0;
}