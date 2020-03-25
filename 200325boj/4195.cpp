/**
*	BOJ
*	No.4195	친구 네트워크
*	@author	peter9378
*	@date		2020.03.25
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

int arr[200002];
int network[200002];

int check(int target)
{
	if (target == network[target])
		return target;
	return network[target] = check(network[target]);
}

int merge(int x, int y)
{
	x = check(x);
	y = check(y);

	if (x != y)
	{
		network[x] = y;
		arr[y] += arr[x];
		arr[x] = 1;
	}
	return arr[y];
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
		int F;
		cin >> F;

		for (int i = 0; i < F * 2; i++)
		{
			arr[i] = 1;
			network[i] = i;
		}

		map<string, int> m;
		int counting = 0;
		for (int i = 0; i < F; i++)
		{
			string a, b;
			cin >> a >> b;

			if (m.count(a) == 0)
				m[a] = counting++;
			if (m.count(b) == 0)
				m[b] = counting++;

			cout << merge(m[a], m[b]) << "\n";
		}
	}

	return 0;
}