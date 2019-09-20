/**
*	BOJ
*	No.2869	달팽이는 올라가고 싶다
*	@author	peter9378
*	@date		2019.09.20
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long A, B, V;
	cin >> A >> B >> V;

	cout << (V - B - 1) / (A - B) + 1;

	return 0;
}