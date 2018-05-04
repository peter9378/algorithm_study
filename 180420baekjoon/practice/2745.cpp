/**
*	baekjoon online judge
*	No. 2745	진법 변환
*	@author	peter9378
*	@date		2018.05.04
*/
#include <iostream>
#include <string>
using namespace std;


// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string N;
	int B;
	cin >> N >> B;

	int result = 0;
	for (int i = 0; i < N.length(); i++)
	{
		if (N[i] >= '0' && N[i] <= '9')
			result = result*B + N[i] - '0';
		else
			result = result*B + (N[i] + 10 - 'A');
	}

	cout << result;

	return 0;
}