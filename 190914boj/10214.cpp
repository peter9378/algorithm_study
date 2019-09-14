/**
*	BOJ
*	No.10214	Baseball
*	@author	peter9378
*	@date		2019.09.14
*/
#include <iostream>
#include <algorithm>
#include <string>
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
		int a = 0, b = 0;
		for (int i = 0; i < 9; i++)
		{
			int c, d;
			cin >> c >> d;
			a += c;
			b += d;
		}
		if (a > b)
			cout << "Yonsei\n";
		else if (a < b)
			cout << "Korea\n";
		else
			cout << "Draw\n";
	}

	return 0;
}