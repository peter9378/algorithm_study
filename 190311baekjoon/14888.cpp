/**
*	baekjoon online judge
*	No. 14888	연산자 끼워넣기
*	@author	peter9378
*	@date		2019.03.11
*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[15];
int N, max_answer = -1000000000, min_answer = 1000000000;

// dfs
void dfs(int pl, int mi, int mu, int di, int count, int sum)
{
	if (count == N)
	{
		max_answer = max(max_answer, sum);
		min_answer = min(min_answer, sum);
	}

	if (pl > 0)
		dfs(pl - 1, mi, mu, di, count + 1, sum + arr[count]);
	if (mi > 0)
		dfs(pl, mi-1, mu, di, count + 1, sum - arr[count]);
	if (mu > 0)
		dfs(pl, mi, mu-1, di, count + 1, sum * arr[count]);
	if (di > 0)
		dfs(pl, mi, mu, di-1, count + 1, sum / arr[count]);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int plus, minus, multiply, division;
	cin >> plus >> minus >> multiply >> division;

	// run dfs
	dfs(plus, minus, multiply, division, 1, arr[0]);

	// print answer
	cout << max_answer << endl << min_answer;
	return 0;
}
