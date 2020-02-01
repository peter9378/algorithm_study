/**
*	BOJ
*	No.1613	¿ª»ç
*	@author	peter9378
*	@date		2020.02.01
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

int arr[404][404];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;

		arr[a][b] = -1;
		arr[b][a] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (arr[j][i] == 1 && arr[i][k] == 1)
				{
					arr[j][k] = 1;
					arr[k][j] = -1;
				}
			}
		}
	}

	int s;
	cin >> s;

	for (int i = 0; i < s; i++)
	{
		int a, b;
		cin >> a >> b;

		cout << arr[a][b] << "\n";
	}

	return 0;
}
