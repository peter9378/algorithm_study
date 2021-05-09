/**
*	BOJ
*	No.3003	Å·, ±Ï, ·è, ºñ¼ó, ³ªÀÌÆ®, Æù
*	@author	peter9378
*	@date		2021.05.09
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

int arr[6] = { 1, 1, 2, 2, 2, 8 };

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 6; i++)
	{
		int temp;
		cin >> temp;
		cout << arr[i] - temp << " ";
	}

	return 0;
}
