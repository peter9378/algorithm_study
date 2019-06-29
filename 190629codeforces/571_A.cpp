/**
*	Code Forces
*	#571 A.	Vus the Cossack and a Contest
*	@author	peter9378
*	@date		2019.06.28
*/
#include <iostream>
#include <algorithm>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int n, m, k;
	cin >> n >> m >> k;

	if (n > min(m, k))
		cout << "No";
	else
		cout << "Yes";

	return 0;
}