/**
*	BOJ
*	No.14470    ¿¿¿¿¿
*	@author	peter9378
*	@date		2021.07.15
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

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    if (a < 0) cout << -1 * a * c + d + e * b;
    else if (a > 0) cout << e * (b - a);
    else cout << d + e * b;

	return 0;
}
