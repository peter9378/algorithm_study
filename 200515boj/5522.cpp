/**
*	BOJ
*	No.5522	카드 게임
*	@author	peter9378
*	@date		2020.05.15
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

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = 0;
	for (int i = 0; i < 5; i++)
	{
		int temp;
		cin >> temp;
		answer += temp;
	}

	cout << answer;

	return 0;
}