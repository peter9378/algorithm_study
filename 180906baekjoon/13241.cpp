/**
*	baekjoon online judge
*	No. 13241	�ּҰ����
*	@author	peter9378
*	@date		2018.09.06
*/
#include <iostream>
using namespace std;

long long int gcd(long long int a, long long int b)
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

	// ���� �Է�
	long long int A, B;
	cin >> A >> B;

	// ��� �� ���
	long long int g = A > B ? gcd(A, B) : gcd(B, A);
	cout << A * B / g << "\n";

	return 0;
}