/**
*	BOJ
*	No.1107	¸®¸ðÄÁ
*	@author	peter9378
*	@date		2019.11.05
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool arr[10];

int check(int n)
{
	if (n == 0)
	{
		if (arr[0]) return 0;
		else return 1;
	}

	int length = 0;
	while (n > 0)
	{
		if (arr[n % 10])
			return 0;
		n /= 10;
		length++;
	}
	return length;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		arr[temp] = true;
	}

	int answer = abs(N - 100);

	for (int i = 0; i < 1000001; i++)
	{
		int temp = i;
		int length = check(temp);
		if (length)
			answer = min(answer, abs(temp - N) + length);
	}
	cout << answer;

	return 0;
}