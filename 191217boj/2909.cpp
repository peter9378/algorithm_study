/**
*	BOJ
*	No.2909	Äµµð ±¸¸Å
*	@author	peter9378
*	@date		2019.12.17
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
#include <cstring>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	double C, K;
	cin >> C >> K;

	long long temp = pow(10, K);
	cout << (long long)round(C / temp)*temp;

	return 0;
}
