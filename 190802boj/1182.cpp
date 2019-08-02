/**
*	BOJ
*	No. 1182	부분수열의 합
*	@author	peter9378
*	@date		2019.08.02
*/
#include <iostream>
#include <string>
using namespace std;

int arr[21];
int answer = 0;
int N, S;

void dfs(int index, int num)
{
	num += arr[index];
	if (index >= N)
		return;
	if (num == S)
		answer++;

	dfs(index + 1, num - arr[index]);
	dfs(index + 1, num);
}


// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	dfs(0, 0);

	cout << answer;

	return 0;
}