/**
*	Code Forces
*	#569 A.	Alex and a Rhombus
*	@author	peter9378
*	@date		2019.06.22
*/
#include <iostream>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N;
	cin >> N;

	// print answer
	// N^2 + (N-1)^2
	cout << 2 * N*N - 2 * N + 1;

	return 0;
}