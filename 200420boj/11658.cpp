/**
*	BOJ
*	No.11658	구간 합 구하기 3
*	@author	peter9378
*	@date		2020.04.20
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
#include <iterator>
#include <numeric>
using namespace std;

int N, M;
int arr[1111][1111];
int tree[1111][1111];

void update(int x, int y, int target)
{
	int result = x;
	while (result <= N)
	{
		int temp = y;
		while (temp <= N)
		{
			tree[result][temp] += target;
			temp += (temp&-temp);
		}
		result += (result&-result);
	}
	return;
}

int process(int x, int y)
{
	int result = 0;
	int a = y;
	while (a)
	{
		int b = x;
		while (b)
		{
			result += tree[b][a];
			b -= (b&-b);
		}
		a -= (a&-a);
	}
	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
			update(i, j, arr[i][j]);
		}
	}

	for (int i = 0; i < M; i++)
	{
		int w;
		cin >> w;

		if (w)
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << process(x2, y2) - process(x2, y1 - 1) - process(x1 - 1, y2) + process(x1 - 1, y1 - 1) << "\n";
		}
		else
		{
			int x, y, c;
			cin >> x >> y >> c;

			update(x, y, c - arr[x][y]);
			arr[x][y] = c;
		}
	}

	return 0;
}