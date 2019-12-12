/**
*	BOJ
*	No.1717	집합의 표현
*	@author	peter9378
*	@date		2019.12.12
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

vector<int> v;

int findd(int target)
{
	if (target == v[target])
		return target;
	return v[target] = findd(v[target]);
}

void unionn(int a, int b)
{
	a = findd(a);
	b = findd(b);
	v[a] = b;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		v.push_back(i);

	for (int i = 0; i < m; i++)
	{
		int command, a, b;
		cin >> command >> a >> b;

		if (command)
		{
			if (findd(a) == findd(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
			unionn(a, b);
	}

	return 0;
}
