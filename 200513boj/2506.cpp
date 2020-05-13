/**
*	BOJ
*	No.2506	점수계산
*	@author	peter9378
*	@date		2020.05.13
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

	int N, answer = 0;
	cin >> N;

	bool flag = false;
	int stk = 1;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		if (temp && flag)
			answer += stk++;
		else if (temp)
		{
			answer += stk++;
			flag = true;
		}
		else
		{
			flag = false;
			stk = 1;
		}
	}

	cout << answer;

	return 0;
}