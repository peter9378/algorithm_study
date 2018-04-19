/**
*	baekjoon online judge
*	No. 10992 별 찍기-17
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

	for (int i = 0; i < N-1; i++)
	{
		for (int j = 0; j < N-i-1; j++)
			cout << " ";
		cout << "*";

		for (int j = 0; j < 2*i-1; j++)
			cout << " ";
		if(i)
			cout << "*";
		cout << "\n";
	}
	for (int i = 0; i < 2*N-1; i++)
		cout << "*";

	return 0;
}