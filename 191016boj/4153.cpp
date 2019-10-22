/**
*	BOJ
*	No.4153	Á÷°¢»ï°¢Çü
*	@author	peter9378
*	@date		2019.10.16
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	while (true)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;
		vector<int> v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);

		sort(v.begin(), v.end());
		a = v[0];
		b = v[1];
		c = v[2];

		if (a*a + b * b == c * c)
			cout << "right\n";
		else
			cout << "wrong\n";
	}

	return 0;
}