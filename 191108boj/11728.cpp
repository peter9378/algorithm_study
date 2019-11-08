/**
*	BOJ
*	No.11728	배열 합치기
*	@author	peter9378
*	@date		2019.11.08
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> a(N);
	vector<int> b(M);
	for (int i = 0; i < N; i++)
		cin >> a[i];

	for (int i = 0; i < M; i++)
		cin >> b[i];

	vector<int> answer;
	int i = 0, j = 0;
	while (true)
	{
		if (a[i] > b[j])
			answer.push_back(b[j++]);
		else if (a[i] < b[j])
			answer.push_back(a[i++]);
		else
		{
			answer.push_back(a[i++]);
			answer.push_back(b[j++]);
		}

		if (i == a.size())
		{
			for (int k = j; k < b.size(); k++)
				answer.push_back(b[k]);
			break;
		}
		else if (j == b.size())
		{
			for (int k = i; k < a.size(); k++)
				answer.push_back(a[k]);
			break;
		}
	}

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";

	return 0;
}