/**
*	baekjoon online judge
*	No. 2455	지능형 기차
*	@author	peter9378
*	@date		2018.09.09
*/
#include <iostream>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int in, out, current = 0, max=-1;
	for (int i = 0; i < 4; i++)
	{
		cin >> out >> in;
		current += (in - out);
		if (max < current)
			max = current;
	}

	cout << max;

	return 0;
}