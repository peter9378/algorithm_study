/**
*	Codeforces
*	#Contest 19	A. XORinacci
*	@author	peter9378
*	@date		2019.08.26
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		vector<unsigned long long> v;
		unsigned long long a, b, n, temp;
		cin >> a >> b >> n;

		v.push_back(a);
		v.push_back(b);

		n %= 3;
		if (n == 2)
			cout << (a ^ b) << "\n";
		else if (n == 1)
			cout << b << "\n";
		else
			cout << a << "\n";
	}


	return 0;
}