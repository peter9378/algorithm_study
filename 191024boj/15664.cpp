/**
*	BOJ
*	No.15664	N°ú M(10)
*	@author	peter9378
*	@date		2019.10.24
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int N, M;
vector<int> v;
set<vector<int>> s;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	do
	{
		vector<int> temp;
		for (int i = 0; i < M; i++)
			temp.push_back(v[i]);
		s.insert(temp);
	} while (next_permutation(v.begin(), v.end()));

	for (auto iter = s.begin(); iter != s.end(); iter++)
	{
		bool flag = false;
		for (int i = 1; i < iter->size(); i++)
		{
			if (iter->at(i - 1) > iter->at(i))
			{
				flag = true;
				break;
			}
		}
		if (flag)
			continue;

		for (int i = 0; i < iter->size(); i++)
			cout << iter->at(i) << " ";
		cout << "\n";
	}

	return 0;
}