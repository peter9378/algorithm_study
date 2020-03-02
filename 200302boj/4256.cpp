/**
*	BOJ
*	No.4256	Æ®¸®
*	@author	peter9378
*	@date		2020.03.02
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

int n;
int arr[1001];
int temp[1001];

void dfs(int a, int b, int c)
{
	if (b > c)
		return;
	if (b == c) {
		cout << arr[a] << ' ';
		return;
	}

	int tmp = temp[arr[a]];
	dfs(a + 1, b, tmp - 1);
	dfs(a + tmp - b + 1, tmp + 1, c);
	cout << arr[a] << ' ';
}


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		for (int i = 1; i <= n; i++)
		{
			int tmp;
			cin >> tmp;

			temp[tmp] = i;
		}
		dfs(1, 1, n);
		cout << "\n";
	}

	return 0;
}