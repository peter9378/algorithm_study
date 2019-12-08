/**
*	BOJ
*	No.1059	¼ö2
*	@author	peter9378
*	@date		2019.12.08
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	v.push_back(0);
	N++;

	int target;
	cin >> target;
	sort(v.begin(), v.end());

	int answer = 0;
	for (int i = 0; i < N - 1; i++)
	{
		if (v[i] < target && target < v[i + 1])
		{
			for (int j = v[i] + 1; j < v[i + 1]; j++)
			{
				for (int k = j + 1; k < v[i + 1]; k++)
				{
					if (j <= target && target <= k)
						answer++;
				}
			}
			break;
		}
	}
	cout << answer;

	return 0;
}