/**
*	BOJ
*	No.1312	¼Ò¼ö
*	@author	peter9378
*	@date		2020.06.11
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

	int A, B, N;
	cin >> A >> B >> N;

	int answer = A % B;

	for (int i = 0; i < N - 1; i++)
	{
		answer *= 10;
		answer %= B;
	}

	cout << answer * 10 / B;

	return 0;
}