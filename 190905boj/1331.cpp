/**
*	BOJ
*	No.1331	나이트 투어
*	@author	peter9378
*	@date		2019.09.05
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define MAX 6

bool visit[MAX][MAX];

bool isValid()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (!visit[i][j])
				return false;
		}
	}
	return true;
}

bool promise(pair<int, int> a, pair<int, int> b)
{
	if (abs(a.first - b.first) == 2)
	{
		if (abs(a.second - b.second) == 1)
			return true;
		return false;
	}
	else if (abs(a.first - b.first) == 1)
	{
		if (abs(a.second - b.second) == 2)
			return true;
	}
	return false;
}

pair<int, int> parse(string s)
{
	return make_pair(s[0] - 'A', (s[1] - 49));
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int T = 35;
	bool flag = true;
	string s;
	cin >> s;
	pair<int, int> first = parse(s);
	visit[first.first][first.second] = true;
	pair<int, int> current = first;

	while (T--)
	{
		cin >> s;
		pair<int, int> temp = parse(s);

		if (promise(current, temp))
		{
			visit[temp.first][temp.second] = true;
			current = temp;
		}
		else
		{
			flag = false;
			break;
		}
	}

	if (flag)
	{
		// check go back to first
		if (promise(current, first) && isValid())
			cout << "Valid";
		else
			cout << "Invalid";
	}
	else
		cout << "Invalid";

	return 0;
}