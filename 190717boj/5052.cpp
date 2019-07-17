/**
*	BOJ
*	No.5052	전화번호 목록
*	@author	peter9378
*	@date		2019.07.17
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	string temp;
	while (T--)
	{
		int N;
		cin >> N;

		vector<string> v;
		while (N--)
		{
			cin >> temp;
			v.push_back(temp);
		}

		sort(v.begin(), v.end());

		int i;
		for (i = 0; i < v.size()-1; i++)
		{
			bool flag = true;
			for (int j = 0; j < v[i].length(); j++)
			{
				if (v[i][j] != v[i + 1][j])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				cout << "NO\n";
				i = v.size();
				break;
			}
		}
		if (i != v.size())
			cout << "YES\n";
	}

	return 0;
}
