/**
*	BOJ
*	No.10610	30
*	@author	peter9378
*	@date		2019.12.30
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

bool compare(char a, char b)
{
	return a > b;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string N;
	cin >> N;

	bool flag = true;
	long long sum = 0;
	for (int i = 0; i < N.length(); i++)
	{
		sum += (N[i] - '0');
		if ((N[i] - '0') == 0)
			flag = false;
	}

	if (sum % 3 || flag)
		cout << "-1";
	else
	{
		sort(N.begin(), N.end(), compare);
		cout << N;
	}

	return 0;
}
