/**
*	BOJ
*	No.2422	한윤정이 이탈리아에 가서 아이스크림을 사먹는데
*	@author	peter9378
*	@date		2021.01.30
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
#include <complex>
using namespace std;

bool check[202][202];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		check[a][b] = check[b][a] = true;
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (check[i][j])
				continue;

			for (int k = j + 1; k <= N; k++)
			{
				if (check[i][k] || check[j][k])
					continue;
				answer++;
			}
		}
	}

	cout << answer;

	return 0;
}
