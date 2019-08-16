/**
*	BOJ
*	No.1351	무한 수열
*	@author	peter9378
*	@date		2019.08.16
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

long long int N, P, Q;
map<long long, long long> m;

long long recursive(long long target)
{
	if (m.count(target))
		return m[target];
	else
		return m[target] = recursive(target / P) + recursive(target / Q);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> P >> Q;
	m[0] = 1;
	cout << recursive(N);

	return 0;
}