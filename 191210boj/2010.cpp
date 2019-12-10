/**
*	BOJ
*	No.2010	ÇÃ·¯±×
*	@author	peter9378
*	@date		2019.12.10
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <cstring>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		answer += temp;
	}
	cout << answer + 1 - N;

	return 0;
}
