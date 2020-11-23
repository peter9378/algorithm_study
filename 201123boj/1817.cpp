/**
*	BOJ
*	No.1817	Áü Ã¬±â´Â ¼ò
*	@author	peter9378
*	@date		2020.11.23
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

bool check[100001];

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	int current = 0, answer = 0;
	while (current < N)
	{
		int temp;
		answer++;
		temp = M;
		for (int i = 0; i < N; i++)
		{
			if (!check[i] && temp >= v[i])
			{
				check[i] = true;
				current++;
				temp -= v[i];
			}
			else if (temp < v[i])
				break;
		}
	}

	cout << answer;

	return 0;
}