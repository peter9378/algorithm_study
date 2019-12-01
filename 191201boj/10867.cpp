/**
*	BOJ
*	No.10867	중복 빼고 정렬하기
*	@author	peter9378
*	@date		2019.12.01
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> v;
	set<int> s;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		if (s.find(temp) == s.end())
		{
			s.insert(temp);
			v.push_back(temp);
		}
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}
