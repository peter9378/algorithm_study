/**
*	BOJ
*	No.10448	유레카 이론
*	@author	peter9378
*	@date		2020.01.10
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
#include <cstring>
using namespace std;

vector<int> v;

void init()
{
	int temp = 1, index = 2;
	while (v.empty() || v.back() <= 1000)
	{
		v.push_back(temp);
		temp += index++;
	}
	v.pop_back();
	return;
}

bool check(int K)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i; j < v.size(); j++)
		{
			for (int k = j; k < v.size(); k++)
			{
				if ((v[i] + v[j] + v[k]) == K)
					return true;
			}
		}
	}
	return false;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	init();
	while (T--)
	{
		int K;
		cin >> K;
		cout << check(K) << "\n";
	}

	return 0;
}
