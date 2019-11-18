/**
*	BOJ
*	No.2357	ÃÖ¼Ú°ª°ú ÃÖ´ñ°ª
*	@author	peter9378
*	@date		2019.11.18
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

int arr[100001];
pair<int, int> segment[333333];

pair<int, int> init(int left, int right, int index)
{
	if (left == right)
		return segment[index] = { arr[left], arr[left] };
	int mid = left + (right - left) / 2;

	pair<int, int> l = init(left, mid, index * 2);
	pair<int, int> r = init(mid + 1, right, index * 2 + 1);
	return segment[index] = { min(l.first, r.first), max(l.second, r.second) };
}

pair<int, int> solution(int index, int left, int right, int from, int to)
{
	if (from > right || to < left)
		return { 1000000000, 0 };
	if (from <= left && right <= to)
		return segment[index];

	int mid = left + (right - left) / 2;
	pair<int, int> l = solution(index * 2, left, mid, from, to);
	pair<int, int> r = solution(index * 2 + 1, mid + 1, right, from, to);
	return { min(l.first, r.first), max(l.second, r.second) };
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	init(0, N - 1, 1);

	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;

		pair<int, int> answer = solution(1, 1, N, from, to);
		cout << answer.first << " " << answer.second << "\n";
	}

	return 0;
}
