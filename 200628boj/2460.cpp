/**
*	BOJ
*	No.2460	지능형 기차 2
*	@author	peter9378
*	@date		2020.06.28
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

	int answer = 0, sum = 0;
	for (int i = 0; i < 10; i++)
	{
		int a, b;
		cin >> a >> b;
		sum += (b - a);
		answer = max(answer, sum);
	}

	cout << answer;

	return 0;
}
