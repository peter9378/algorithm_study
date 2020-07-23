/**
*	BOJ
*	No.1236	성 지키기
*	@author	peter9378
*	@date		2020.07.23
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

char arr[55][55];
bool a[55];
bool b[55];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = s[j];
			if (arr[i][j] == 'X')
			{
				a[i] = true;
				b[j] = true;
			}
		}
	}

	int c = 0, r = 0;
	for (int i = 0; i < N; i++)
	{
		if (!a[i])
			r++;
	}

	for (int i = 0; i < M; i++)
	{
		if (!b[i])
			c++;
	}

	cout << (c > r ? c : r);

	return 0;
}