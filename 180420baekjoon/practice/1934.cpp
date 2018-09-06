/**
*	baekjoon online judge
*	No. 1934	최소공배수
*	@author	peter9378
*	@date		2018.05.01
*/
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (a%b)
		return gcd(b, a%b);
	else
		return b;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 테스트 케이스 개수 입력
	int T;
	cin >> T;

	// 테스트 케이스 루프
	while (T--)
	{
		// 숫자 입력
		int A, B;
		cin >> A >> B;

		// 계산 후 출력
		int g = A > B ? gcd(A, B) : gcd(B, A);
		cout << A*B/g << "\n" ;
	}

	return 0;
}