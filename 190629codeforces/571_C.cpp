/**
*	Code Forces
*	#571 C.	Vus the Cossack and Strings
*	@author	peter9378
*	@date		2019.06.29
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// main function
int main() {
	string a, b;
	cin >> a >> b;

	int total = 0;
	for (int i = 0; i < b.length(); i++)
		total += b[i] - '0';

	for (int i = 0; i < b.length() - 1; i++)
		total += a[i] - '0';

	int answer = 0;
	total += a[b.length() - 1] - '0';
	if (total % 2 == 0)
		answer++;
	for (int i = 1; i + b.length() - 1 < a.length(); ++i)
	{
		total += a[i + b.length() - 1] - '0';
		total -= a[i - 1] - '0';

		if (total % 2 == 0)
			answer++;
	}

	cout << answer;

	return 0;
}