/**
*	Codeforces
*	#581		B. Mislove Has Lost an Array
*	@author	peter9378
*	@date		2019.08.21
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l, r;
	cin >> n >> l >> r;

	long long answer_min = 0;
	long long answer_max = 0;

	int temp = n;
	long long add = 1;
	int count = 0;

	// get min
	if (n > l)
	{
		temp = l;
		while (temp--)
			answer_min += pow(2, temp);
		answer_min += n - l;
	}
	else
		answer_min = pow(2, n) - 1;

	if (n > r)
	{
		temp = r;
		while (temp--)
			answer_max += pow(2, temp);
		answer_max += pow(2, r - 1)*(n - r);
	}
	else
		answer_max = pow(2, n) - 1;

	cout << answer_min << " " << answer_max;


	return 0;
}