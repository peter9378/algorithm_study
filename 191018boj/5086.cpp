/**
*	BOJ
*	No.5086	배수와 약수
*	@author	peter9378
*	@date		2019.10.18
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		int a, b;
		cin >> a >> b;

		if (a == 0 && b == 0)
			break;

		if (a > b)
		{
			if (a%b == 0)
				cout << "multiple\n";
			else
				cout << "neither\n";
		}
		else
		{
			if (b%a == 0)
				cout << "factor\n";
			else
				cout << "neither\n";
		}
	}

	return 0;
}