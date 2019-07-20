/**
*	BOJ
*	No.2588	곱셈
*	@author	peter9378
*	@date		2019.07.20
*/
#include <iostream>
#include <algorithm>
using namespace std;


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;

	int answer = a * b;
	while (b)
	{
		cout << a * (b % 10) << "\n";
		b /= 10;
	}

	cout << answer;

	return 0;
}
