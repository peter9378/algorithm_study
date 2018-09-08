/**
*	baekjoon online judge
*	No. 1094	¸·´ë±â
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

	int x;
	cin >> x;

	int count = 0;
	while (x != 0)
	{
		if (x % 2)
			count++;
		x /= 2;
	}
	cout << count;	
	return 0;
}