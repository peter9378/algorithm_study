/**
*	BOJ
*	No.3053	나머지
*	@author	peter9378
*	@date		2019.07.08 happy birthday!
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool visit[43];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 10; i++)
	{
		int temp;
		cin >> temp;
		visit[temp % 42] = true;
	}

	int answer = 0;
	for (int i = 0; i < 43; i++)
	{
		if (visit[i])
			answer++;
	}

	cout << answer;

	return 0;
}
