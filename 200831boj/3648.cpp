/**
*	BOJ
*	No.3648	æ∆¿Ãµπ
*	@author	peter9378
*	@date		2020.08.31
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

int N, M, a, b, c, d;
vector<vector<int>> arr;
vector<int> check;
vector<int> sc;
stack<int> stk;

void go(int a, int b)
{
	arr[a ^ 1].emplace_back(b);
	arr[b ^ 1].emplace_back(a);
	return;
}

int scc(int target)
{
	int result = check[target] = c++;
	stk.emplace(target);

	for (auto there : arr[target]) {
		if (check[there] == -1)
			result = min(result, scc(there));
		else if (sc[there] == -1)
			result = min(result, check[there]);
	}

	if (result == check[target])
	{
		while (true)
		{
			int t = stk.top();
			stk.pop();
			sc[t] = d;
			if (t == target)
				break;
		}
		d++;
	}
	return result;
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> N >> M)
	{
		c = d = 0;
		arr.clear();
		arr.resize(N << 1);
		check.clear();
		sc.clear();

		check = sc = vector<int>(N << 1, -1);

		while (M--)
		{
			cin >> a >> b;
			a = a > 0 ? (a - 1) << 1 : (~a << 1 | 1);
			b = b > 0 ? (b - 1) << 1 : (~b << 1 | 1);
			go(a, b);
		}

		for (int i = 0; i < N << 1; i++)
		{
			if (check[i] == -1)
				scc(i);
		}

		bool flag = true;
		for (int i = 0; i < N; i++)
		{
			if (sc[i] == sc[i ^ 1])
			{
				flag = false;
				break;
			}
		}

		if (sc[0] > sc[1])
			flag = false;

		cout << (flag ? "yes" : "no") << "\n";
	}

	return 0;
}