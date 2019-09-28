/**
*	BOJ
*	No.2231	분해합
*	@author	peter9378
*	@date		2019.09.28
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;

bool is_promise(int n)
{
	int temp = n;
	while (n)
	{
		temp += n % 10;
		n /= 10;
	}
	return temp == N;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int i;
	for (i = 1; i <= N; i++)
	{
		if (is_promise(i))
			break;
	}

	if (is_promise(i))
		cout << i;
	else
		cout << 0;

	return 0;
}