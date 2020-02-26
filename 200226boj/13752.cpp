/**
*	BOJ
*	No.13752	히스토그램
*	@author	peter9378
*	@date		2020.02.26
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

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;

		while (k--)
			cout << "=";
		cout << "\n";
	}

	return 0;
}