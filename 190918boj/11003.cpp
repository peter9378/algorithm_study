/**
*	BOJ
*	No.11003	최솟값 찾기
*	@author	peter9378
*	@date		2019.09.18
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int arr[5000005];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, L;
	cin >> N >> L;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	priority_queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
	{
		q.push(make_pair(-arr[i], i));
		while (q.top().second <= i - L)
			q.pop();
		cout << -q.top().first << ' ';
	}


	return 0;
}