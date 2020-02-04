/**
*	BOJ
*	No.1049	±‚≈∏¡Ÿ
*	@author	peter9378
*	@date		2020.02.04
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

	int N, M;
	cin >> N >> M;

	vector<int> package(M);
	vector<int> cost(M);
	for (int i = 0; i < M; i++)
		cin >> package[i] >> cost[i];

	sort(package.begin(), package.end());
	sort(cost.begin(), cost.end());

	int answer = 0;
	while (N > 0)
	{
		if (N >= 6 && package[0] < cost[0] * 6)
		{
			answer += package[0];
			N -= 6;
		}
		else if (N < 6 && package[0] < cost[0] * N)
		{
			answer += package[0];
			N -= 6;
		}
		else
		{
			answer += cost[0] * N;
			N = 0;
		}
	}

	cout << answer;

	return 0;
}
