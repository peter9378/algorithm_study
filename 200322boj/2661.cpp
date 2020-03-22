/**
*	BOJ
*	No.2661	좋은수열
*	@author	peter9378
*	@date		2020.03.22
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

int n;
int temp[3] = { 1, 2, 3 };
int arr[111];
bool done = false;

void dfs(int index)
{
	string s = "";
	for (int i = 0; i < index; i++)
		s += (arr[i] + '0');

	for (int i = 1; i <= index / 2; i++)
	{
		for (int j = 0; j <= index - 2 * i; j++)
		{
			if (s.substr(j, i) == s.substr(j + i, i))
				return;
		}
	}

	if (index == n)
	{
		for (int i = 0; i < index; i++)
			cout << arr[i];
		exit(0);
	}

	for (int i = 0; i < 3; i++)
	{
		arr[index] = temp[i];
		dfs(index + 1);
		if (done)
			return;
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	dfs(0);

	return 0;
}