/**
*	BOJ
*	No.1166 ¿¿
*	@author	peter9378
*	@date		2021.01.26
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

    int N, L, W, H;
    cin >> N >> L >> W >> H;

    double left = 0, right = 9876543210, mid;
    for(int i = 0; i < 10000; i++)
    {
        mid = (left + right) / 2;

        if (((long long)(L/mid))*((long long)(W/mid))*((long long)(H/mid)) < N)
            right = mid;
        else
            left = mid;
    }

	printf("%.10lf", left);

	return 0;
}
