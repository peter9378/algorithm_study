/**
*	BOJ
*	No.2467	ฟ๋พื
*	@author	peter9378
*	@date		2020.08.03
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
#include <unordered_map>
#include <cstring>
#include <iterator>
#include <numeric>
using namespace std;

// main function
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

	sort(v.begin(), v.end());

	int left = 0, right = v.size() - 1, current = 2e9;
	pair<int, int> answer;

	while (left < right)
	{
		int a = v[left];
		int b = v[right];

		if (abs(a + b) < current)
		{
			current = abs(a + b);
			answer.first = v[left];
			answer.second = v[right];
		}

		if (a < -b)
			left++;
		else
			right--;
	}

	cout << answer.first << " " << answer.second;

	return 0;
}