/**
*	BOJ
*	No.16953	A ¡æ B
*	@author	peter9378
*	@date		2020.08.05
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
#include <unordered_map>
#include <cstring>
#include <iterator>
#include <numeric>
using namespace std;

long long A, B;
int answer = 987654321;

bool dfs(long long current, int idx)
{
	if (current > B)
		return false;

	for (int i = 0; i < 2; i++)
	{
		long long temp = A;

		if (i == 0)
			A *= 2;
		else
			A = A * 10 + 1;

		if (A == B)
		{
			answer = min(answer, idx + 1);
			return true;
		}

		if (dfs(A, idx + 1))
			return true;

		A = temp;
	}
	return false;
}


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B;
	cout << (dfs(A, 0) ? answer + 1 : -1);

	return 0;
}