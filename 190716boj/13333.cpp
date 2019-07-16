/**
*	BOJ
*	No.13333	Q-인덱스
*	@author	peter9378
*	@date		2019.07.16
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

	int temp;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < N; i++)
	{
		if (v[N - i - 1] >= N - i)
		{
			cout << N - i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
