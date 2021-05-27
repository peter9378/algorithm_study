/**
*	BOJ
*	No.1108	검색 엔진
*	@author	peter9378
*	@date		2021.05.27
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

int VC, SC;

map<string, int> arr;
vector<vector<int>> v;
vector<vector<pair<int, int>>> sccv;
vector<int> sccid, discovered;

vector<long long> cache;
stack<int> stk;

int scc(int target)
{
	int result = discovered[target] = VC++;
	stk.emplace(target);

	for (auto a : v[target])
	{
		if (discovered[a] == -1)
			result = min(result, scc(a));
		else if (sccid[a] == -1)
			result = min(result, discovered[a]);
	}

	if (result == discovered[target])
	{
		while (true)
		{
			int current = stk.top();
			stk.pop();
			sccid[current] = SC;

			if (current == target)
				break;
		}
		SC++;
	}
	return result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	v.resize(2501);

	string s, ss;
	int b, temp = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> s >> b;
		if (arr.find(s) == arr.end())
			arr[s] = temp++;

		for (int j = 0; j < b; j++)
		{
			cin >> ss;

			if (arr.find(ss) == arr.end())
				arr[ss] = temp++;
			v[arr[ss]].emplace_back(arr[s]);
		}
	}

	string word;
	cin >> word;
	if (arr.find(word) == arr.end())
		arr[word] = temp++;

	discovered = sccid = vector<int>(2501, -1);

	for (int i = 0; i < temp; i++)
	{
		if (discovered[i] == -1)
			scc(i);
	}

	sccv.resize(2501);
	for (int here = 0; here < temp; here++)
	{
		for (auto there : v[here])
		{
			if (sccid[here] != sccid[there])
				sccv[sccid[here]].emplace_back(here, there);
		}
	}

	int wt = arr[word];
	cache.resize(2500, 1);
	for (int i = SC - 1; i; --i)
	{
		for (auto a : sccv[i])
			cache[a.second] += cache[a.first];
	}

	cout << cache[wt];

	return 0;
}
