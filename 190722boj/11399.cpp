/**
*	BOJ
*	No.11399	ATM
*	@author	peter9378
*	@date		2019.07.22
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> v;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	int answer = 0;
	for (int i = 0; i < N; i++)
		answer += v[i] * (N - i);

	cout << answer;
	return 0;
}