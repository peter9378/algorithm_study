/**
*	BOJ
*	No.16673	고려대학교에는 공식 와인이 있다
*	@author	peter9378
*	@date		2019.12.08
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int C, K, P;
	cin >> C >> K >> P;

	long long answer = 0;
	for (int i = 1; i <= C; i++)
		answer += (K*i) + (P*i*i);

	cout << answer;

	return 0;
}