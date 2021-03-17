/**
*	BOJ
*	No.15964	이상한 기호
*	@author	peter9378
*	@date		2021.03.17
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <iterator>
#include <numeric>
#include <complex>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long A, B;
	cin >> A >> B;
	cout << (A + B)*(A - B);

	return 0;
}
