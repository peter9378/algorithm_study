/**
*	BOJ
*	No.2753	윤년
*	@author	peter9378
*	@date		2019.07.24
*/
#include <iostream>
#include <algorithm>
using namespace std;


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int year;
	cin >> year;

	if (year % 4 == 0 && (year % 100 || year % 400 == 0))
		cout << 1;
	else
		cout << 0;

	return 0;
}
