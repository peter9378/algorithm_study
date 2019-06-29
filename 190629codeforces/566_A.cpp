/**
*	Code Forces
*	#566 A.	Filling Shapes
*	@author	peter9378
*	@date		2019.06.29
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int n;
	cin >> n;

	if (n % 2)
		cout << 0;
	else
		cout << (long long)(pow(2, n/2));

	return 0;
}