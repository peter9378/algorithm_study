/**
*	BOJ
*	No.1019	책 페이지
*	@author	peter9378
*	@date		2019.12.10
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

int answer[11];

void calc(int n, int sum)
{
	while (n)
	{
		answer[n % 10] += sum;
		n /= 10;
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int sum = 1;
	int page = 1;

	while (page <= N)
	{
		while (N % 10 != 9 && page <= N)
		{
			calc(N, sum);
			N--;
		}

		if (N < page)
			break;

		while (page % 10 && page <= N)
		{
			calc(page, sum);
			page++;
		}

		page /= 10;
		N /= 10;

		for (int i = 0; i < 10; i++)
			answer[i] += (N - page + 1)*sum;

		sum *= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << answer[i] << " ";

	return 0;
}