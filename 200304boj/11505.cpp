/**
*	BOJ
*	No.11505	구간 곱 구하기
*	@author	peter9378
*	@date		2020.03.04
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

int N, M, K;
const int MOD = 1000000007;
long long value;
vector<long long> arr;
vector<long long> tree;

long long init(int target, int start, int end)
{
	if (start == end)
		return tree[target] = arr[start];

	else
		return tree[target] = ((init(target * 2, start, (start + end) / 2) % MOD) * (init(target * 2 + 1, (start + end) / 2 + 1, end) % MOD)) % MOD;
}

long long update(int target, int start, int end, int index)
{
	if (start > index || index > end)
		return tree[target];

	if (start == end)
		return tree[target] = value;

	return tree[target] = (update(target * 2, start, (start + end) / 2, index) * update(target * 2 + 1, (start + end) / 2 + 1, end, index)) % MOD;
}

long long multiply(int target, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 1;

	if (left <= start && end <= right)
		return tree[target];

	return (multiply(target * 2, start, (start + end) / 2, left, right) * multiply(target * 2 + 1, (start + end) / 2 + 1, end, left, right)) % MOD;
}


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	arr.resize(N);
	tree.resize(1 << ((int)ceil(log2(N)) + 1));

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	init(1, 0, N - 1);

	M += K;

	while (M--)
	{
		int a;
		cin >> a;

		if (a == 1)
		{
			int b;
			cin >> b >> value;
			update(1, 0, N - 1, b - 1);
		}
		else if (a == 2)
		{
			int b, c;
			cin >> b >> c;
			cout << multiply(1, 0, N - 1, b - 1, c - 1) % MOD << "\n";
		}
	}

	return 0;
}