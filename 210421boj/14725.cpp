/**
*	BOJ
*	No.14725	°³¹Ì±¼
*	@author	peter9378
*	@date		2021.04.21
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

	int N, K;
	cin >> N;

	vector<string> arr[1001];
	for (int i = 0; i < N; i++)
	{
		cin >> K;
		for (int j = 0; j < K; j++)
		{
			string s;
			cin >> s;
			arr[i].push_back(s);
		}
	}

	sort(arr, arr + N);
	vector<string> v;
	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		for (int j = 0; j < arr[i].size() && j < v.size(); j++)
		{
			if (arr[i][j] == v[j])
				cnt++;
			else
				break;
		}

		int size = v.size();
		for (int j = cnt; j < size; j++)
			v.pop_back();

		for (int j = cnt; j < arr[i].size(); j++)
		{
			for (int k = 0; k < v.size(); k++)
				cout << "--";
			cout << arr[i][j] << "\n";
			v.push_back(arr[i][j]);
		}
	}

	return 0;
}
