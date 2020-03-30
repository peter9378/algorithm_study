/**
*	BOJ
*	No.16562	친구비
*	@author	peter9378
*	@date		2020.03.30
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

int arr[10001];
int tree[10001];

int check(int target)
{
	if (tree[target] < 0)
		return target;
	return tree[target] = check(tree[target]);
}

void merge(int a, int b)
{
	a = check(a);
	b = check(b);

	if (a == b)
		return;
	if (arr[a] < arr[b])
		tree[b] = a;
	else
		tree[a] = b;
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i <= N; i++)
		tree[i] = -1;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	while (M--)
	{
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		if (tree[i] == -1)
			answer += arr[i];
	}

	if (K < answer)
		cout << "Oh no";
	else
		cout << answer;

	return 0;
}