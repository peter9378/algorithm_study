/**
*	BOJ
*	No.11281	2-SAT - 4
*	@author	peter9378
*	@date		2021.06.09
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

#define W(x) (x>0?(x-1)<<1:(-(x+1)<<1|1))

int VC, SC;

vector<vector<int>> adj;
vector<int> discovered, sccid;
stack<int> st;

void go(int u, int v)
{
	adj[W(u) ^ 1].emplace_back(W(v));
	adj[W(v) ^ 1].emplace_back(W(u));
}

int scc(int target)
{
	int result = discovered[target] = VC++;
	st.emplace(target);

	for (auto there : adj[target])
	{
		if (discovered[there] == -1)
			result = min(result, scc(there));
		else if (sccid[there] == -1)
			result = min(result, discovered[there]);
	}

	if (result == discovered[target])
	{
		while (true)
		{
			int current = st.top();
			st.pop();

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

	int N, M;
	cin >> N >> M;

	adj.resize(N << 1);
	int u, v;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		go(u, v);
	}

	discovered = sccid = vector<int>(N << 1, -1);
	for (int i = 0; i < N << 1; i++)
	{
		if (discovered[i] == -1)
			scc(i);
	}

	bool flag = true;
	for (int i = 0; i < N; i++)
	{
		if (sccid[i << 1] == sccid[i << 1 | 1])
		{
			flag = false;
			break;
		}
	}

	cout << flag << "\n";
	if (flag)
	{
		for (int i = 0; i < N; i++)
			cout << (sccid[i << 1] < sccid[i << 1 | 1]) << " ";
	}

	return 0;
}
