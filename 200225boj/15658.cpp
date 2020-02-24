/**
*	BOJ
*	No.15658	연산자 끼워넣기(2)
*	@author	peter9378
*	@date		2020.02.25
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

int N;
int arr[11];
int oper[4];
int max_answer = -987654321, min_answer = 987654321;

void dfs(int index, int current, int add, int minus, int multiple, int divide)
{
	if (index >= N)
	{
		max_answer = max(current, max_answer);
		min_answer = min(current, min_answer);
		return;
	}

	if (add)
		dfs(index + 1, current + arr[index], add - 1, minus, multiple, divide);
	if (minus)
		dfs(index + 1, current - arr[index], add, minus - 1, multiple, divide);
	if (multiple)
		dfs(index + 1, current * arr[index], add, minus, multiple - 1, divide);
	if (divide)
		dfs(index + 1, current / arr[index], add, minus, multiple, divide - 1);
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];
	dfs(1, arr[0], oper[0], oper[1], oper[2], oper[3]);
	cout << max_answer << "\n" << min_answer;

	return 0;
}
