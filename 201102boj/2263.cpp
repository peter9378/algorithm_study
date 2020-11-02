/**
*	BOJ
*	No.2263	트리의 순회
*	@author	peter9378
*	@date		2020.11.02
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

#define MAX 100001

int arr[MAX];
int in[MAX];
int pre[MAX];
int post[MAX];

void go(int in_start, int in_end, int post_start, int post_end)
{
	if (in_start > in_end || post_start > post_end)
		return;

	int root = post[post_end];
	cout << root << " ";

	int p = arr[root];
	int left = p - in_start;
	go(in_start, p - 1, post_start, post_start + left - 1);
	go(p + 1, in_end, post_start + left, post_end - 1);

	return;
}

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> in[i];
	for (int i = 0; i < N; i++)
		cin >> post[i];
	for (int i = 0; i < N; i++)
		arr[in[i]] = i;

	go(0, N - 1, 0, N - 1);

	return 0;
}