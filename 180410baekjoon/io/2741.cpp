/**
*	baekjoon online judge
*	No. 2741 N 찍기
*	@date		2018.04.20
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cout << i + 1 << "\n";

	return 0;
}