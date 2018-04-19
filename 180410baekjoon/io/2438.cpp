/**
*	baekjoon online judge
*	No. 2438 별찍기-1
*	@date		2018.04.20
*/
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = -1; j < i; j++)
			cout << "*";
		cout << "\n";
	}

	return 0;
}