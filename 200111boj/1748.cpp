/**
*	BOJ
*	No.1748	수 이어 쓰기 1
*	@author	peter9378
*	@date		2020.01.11
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

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string N;
	cin >> N;

	long long answer = 0;
	for (int i = 1; i < N.length(); i++)
		answer += i * pow(10, i - 1) * 9;
	answer += (stoi(N) + 1 - pow(10, N.length() - 1))*N.length();

	cout << answer;

	return 0;
}
