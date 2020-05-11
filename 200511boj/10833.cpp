/**
*	BOJ
*	No.10833	»ç°ú
*	@author	peter9378
*	@date		2020.05.11
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

	int N;
	cin >> N;

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;

		while (a <= b)
			b -= a;

		answer += b;
	}

	cout << answer;

	return 0;
}