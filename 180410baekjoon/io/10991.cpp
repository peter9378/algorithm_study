/**
*	baekjoon online judge
*	No. 10991 별 찍기-16
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
		for (int j = 0; j < N-i-1; j++)
			cout << " ";
		cout << "*";
		for (int j = 0; j < i; j++)
			cout << " *";
		cout << "\n";
	}

	return 0;
}