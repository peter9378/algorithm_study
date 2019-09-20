/**
*	BOJ
*	No.2798	블랙잭
*	@author	peter9378
*	@date		2019.09.20
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> v;
	vector<int> check;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 0; i < N - 3; i++)
		check.push_back(0);
	check.push_back(1);
	check.push_back(1);
	check.push_back(1);
	sort(v.begin(), v.end());
	sort(check.begin(), check.end());

	int answer = -1;
	do
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (check[i])
				sum += v[i];
		}
		if (sum <= M)
			answer = max(answer, sum);
	} while (next_permutation(check.begin(), check.end()));

	cout << answer;

	return 0;
}