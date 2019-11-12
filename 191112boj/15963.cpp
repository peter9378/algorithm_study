/**
*	BOJ
*	No.15963	CASIO
*	@author	peter9378
*	@date		2019.11.12
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

	string a, b;
	cin >> a >> b;

	if (a == b) cout << 1;
	else cout << 0;

	return 0;
}