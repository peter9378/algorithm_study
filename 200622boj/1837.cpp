/**
*	BOJ
*	No.1837	암호 제작
*	@author	peter9378
*	@date		2020.06.22
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
#include <iterator>
#include <numeric>
using namespace std;

string s;
int k, prime[2000002];

bool check(int p)
{
	int result = 0;
	for (int i = 0; s[i]; i++)
		result = (result * 10 + (s[i] - '0')) % p;
	return !result;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s >> k;
	bool flag = true;
	int answer = 0;
	for (int i = 2; i < k; i++)
	{
		if (prime[i])
			continue;
		if (check(i))
		{
			flag = false;
			answer = i;
			break;
		}
		for (int j = i * 2; j < k; j += i)
			prime[j] = true;
	}

	if (flag)
		cout << "GOOD";
	else
		cout << "BAD " << answer;

	return 0;
}
