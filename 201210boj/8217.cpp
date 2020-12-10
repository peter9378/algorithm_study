/**
*	BOJ
*	No.8217	À¯¼º
*	@author	peter9378
*	@date		2020.12.10
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

struct que {
	int left, right, value;
};

const int mod = 1e9 + 7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;
int N, M, K;
long long tr[300003];
int leftarr[300003];
int rightarr[300003];
int need[300003];
que qq[300003];
vector<int> qry[300003];
vector<int> arr[300003];

void update(int pos, int val)
{
	while (pos <= M)
	{
		tr[pos] += val;
		pos += pos & -pos;
	}
}
long long query(int pos) {
	long long ret = 0;
	while (pos > 0) {
		ret += tr[pos];
		pos -= pos & -pos;
	}
	return ret;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		int temp;
		cin >> temp;
		arr[temp].push_back(i);
	}

	for (int i = 1; i <= N; i++)
		cin >> need[i];

	cin >> K;

	for (int i = 1; i <= K; i++)
	{
		int l, r, a;
		cin >> l >> r >> a;
		qq[i] = { l, r, a };
	}

	for (int i = 1; i <= N; i++)
	{
		leftarr[i] = 1;
		rightarr[i] = K + 1;
	}

	while (true)
	{
		bool flag = true;
		for (int i = 1; i <= N; i++)
		{
			if (leftarr[i] < rightarr[i])
			{
				flag = false;
				int mid = (leftarr[i] + rightarr[i]) / 2;
				qry[mid].push_back(i);
			}
		}

		if (flag)
			break;

		memset(tr, 0, sizeof(tr));

		for (int i = 1; i <= K; i++)
		{
			auto q = qq[i];
			if (q.left > q.right)
			{
				update(q.left, q.value);
				update(1, q.value);
				update(q.right + 1, -q.value);
			}
			else
			{
				update(q.left, q.value);
				update(q.right + 1, -q.value);
			}

			while (qry[i].size())
			{
				int id = qry[i].back();
				qry[i].pop_back();
				long long sum = 0;
				for (int nd : arr[id])
				{
					sum += query(nd);
					if (sum >= need[id])
						break;
				}

				if (sum >= need[id])
					rightarr[id] = i;
				else
					leftarr[id] = i + 1;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (leftarr[i] == K + 1)
			cout << "NIE\n";
		else
			cout << leftarr[i] << "\n";
	}

	return 0;
}
