/**
*	BOJ
*	No.15829	Hashing
*	@author	peter9378
*	@date		2020.07.13
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

#define MOD 1234567891
#define MUL 31

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int L;
	cin >> L;

	string s;
	cin >> s;

	long long answer = 0, temp = 1;
	for (int i = 0; i < s.length(); i++)
	{
		answer = (answer + (s[i] - 'a' + 1)*temp) % MOD;
		temp = (temp*MUL) % MOD;
	}

	cout << answer;

	return 0;
}