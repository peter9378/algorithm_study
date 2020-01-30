/**
*	BOJ
*	No.1030	ÇÁ·ºÅ» Æò¸é
*	@author	peter9378
*	@date		2020.01.30
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

int N, K;
int len;

bool check(int a, int b)
{
	int border = (N - K) / 2, temp = len / N;
	while (temp)
	{
		if (a / temp >= border && a / temp <= N - border - 1 && b / temp >= border && b / temp <= N - border - 1)
			return true;

		if (a >= temp)
			a %= temp;
		if (b >= temp)
			b %= temp;
		temp /= N;
	}
	return false;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int s, R1, R2, C1, C2;
	cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

	len = pow(N, s);

	for (int i = R1; i <= R2; i++)
	{
		for (int j = C1; j <= C2; j++)
			cout << check(i, j);
		cout << "\n";
	}

	return 0;
}
