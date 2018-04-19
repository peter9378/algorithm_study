/**
*	baekjoon online judge
*	No. 2739 구구단
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

	for (int count = 1; count < 10; count++)
		cout << N << " * " << count << " = " << N*count << "\n";

	return 0;
}