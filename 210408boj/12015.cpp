/**
*	BOJ
*	No.12015	가장 긴 증가하는 부분 수열 2
*	@author	peter9378
*	@date		2021.04.08
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
#include <complex>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector <int> v;
	v.push_back(-987654321);
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp > v.back())
		{
			v.push_back(temp);
			answer++;
		}
		else
		{
			vector<int>::iterator low = lower_bound(v.begin(), v.end(), temp);
			*low = temp;
		}
	}

	cout << answer;

	return 0;
}
