/**
*	BOJ
*	No.14897	서로 다른 수와 쿼리
*	@author	peter9378
*	@date		2021.09.03
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

int sqrtn;

int counting[1000001];
int temp = 0;

void add(int target)
{
	if (counting[target] == 0)
		temp++;
	counting[target]++;
}

void sub(int target)
{
	counting[target]--;
	if (counting[target] == 0)
		temp--;
}

struct query {
	int index, i, j;
};
bool compare(query& a, query& b) {
	if (a.i / sqrtn != b.i / sqrtn) return a.i / sqrtn < b.i / sqrtn;
	return a.j < b.j;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	sqrtn = (int)sqrt(N);
	vector<int> arr(N);
	vector<int> temparr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	temparr = arr;
	sort(temparr.begin(), temparr.end());
	temparr.erase(unique(temparr.begin(), temparr.end()), temparr.end());

	for (int i = 0; i < N; i++)
		arr[i] = lower_bound(temparr.begin(), temparr.end(), arr[i]) - temparr.begin();

	int Q;
	cin >> Q;
	vector<query> v(Q);
	vector<int>answer(Q);
	for (int i = 0; i < Q; i++)
	{
		int x, y;
		cin >> x >> y;
		v[i] = { i, x - 1, y - 1 };
	}

	sort(v.begin(), v.end(), compare);

	int start = v[0].i;
	int end = v[0].j;
	for (int i = start; i <= end; i++)
		add(arr[i]);

	answer[v[0].index] = temp;

	for (int i = 1; i < Q; i++)
	{
		while (v[i].i < start)
			add(arr[--start]);
		while (v[i].j > end)
			add(arr[++end]);
		while (v[i].i > start)
			sub(arr[start++]);
		while (v[i].j < end)
			sub(arr[end--]);

		answer[v[i].index] = temp;
	}

	for (int i = 0; i < Q; i++)
		cout << answer[i] << "\n";

	return 0;
}