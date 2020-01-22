/**
*	BOJ
*	No.2822	점수 계산
*	@author	peter9378
*	@date		2020.01.23
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

int arr[1001];
bool visit[1001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<pair<int, int>> q;
	priority_queue<int, vector<int>, greater<int>> qq;

	for (int i = 0; i < 8; i++)
	{
		int temp;
		cin >> temp;
		q.push({ temp, i });
	}

	int answer = 0;
	for (int i = 0; i < 5; i++)
	{
		int score = q.top().first;
		int index = q.top().second;

		qq.push(index);
		q.pop();
		answer += score;
	}

	cout << answer << "\n";

	for (int i = 0; i < 5; i++)
	{
		cout << qq.top() + 1 << " ";
		qq.pop();
	}

	return 0;
}
