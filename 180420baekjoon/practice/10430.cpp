/**
*	baekjoon online judge
*	No. 10430	나머지
*	@author	peter9378
*	@date		2018.05.01
*/
#include <iostream>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int A, B, C;
	cin >> A >> B >> C;

	// 출력
	cout << (A + B) % C << "\n" << (A%C + B%C) % C << "\n" << (A*B) % C << "\n"
		<< ((A%C) * (B%C)) % C;
	return 0;
}