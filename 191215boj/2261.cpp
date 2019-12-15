/**
*	BOJ
*	No.2261	가장 가까운 두 점
*	@author	peter9378
*	@date		2019.12.15
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

#define MAX 1000000000001;

int N;
pair<long long, long long> arr[500005];

long long square(long long a)
{
	return a * a;
}

long long distance(pair<long, long> a, pair<long, long> b)
{
	return square(a.first - b.first) + square(a.second - b.second);
}

bool compare(pair<long, long> a, pair<long, long> b)
{
	if (a.second != b.second)
		return a.second < b.second;
	else
		return a.first < b.first;
}

long long answer(int start, int end)
{
	if (end - start == 1)
		return MAX;

	int mid = (start + end) / 2;
	long long d = min(answer(start, mid), answer(mid, end));
	vector<pair<long, long>> V;
	long long sep = arr[mid].first;
	for (int i = start; i < end; i++)
	{
		if (square(arr[i].first - sep) <= d)
			V.push_back(arr[i]);
	}

	sort(V.begin(), V.end(), compare);

	for (int i = 0; i < V.size(); i++)
	{
		for (int j = i + 1; j < V.size() && j < i + 7; j++)
			d = min(d, distance(V[i], V[j]));
	}
	return d;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;

	sort(arr, arr + N);
	cout << answer(0, N);


	return 0;
}
