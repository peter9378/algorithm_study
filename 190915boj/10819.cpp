/**
*	BOJ
*	No.10819	차이를 최대로
*	@author	peter9378
*	@date		2019.09.15
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	int answer = -1;
	sort(v.begin(), v.end());
	do
	{
		int temp = 0;
		for (int i = 0; i < N - 1; i++)
			temp += abs(v[i] - v[i + 1]);
		answer = max(answer, temp);
	} while (next_permutation(v.begin(), v.end()));

	cout << answer;

	return 0;
}