/**
*	BOJ
*	No.2816	디지털 티비
*	@author	peter9378
*	@date		2020.04.01
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
#include <iterator>
#include <numeric>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int a = -1, b = -1;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		if (s == "KBS1")
			a = i;
		else if (s == "KBS2")
			b = i;
	}

	int check = a > b;
	for (int i = 0; i < a; i++)
		cout << "1";
	for (int i = 0; i < a; i++)
		cout << "4";
	for (int i = 0; i < b + check; i++)
		cout << "1";
	for (int i = 0; i < b + check - 1; i++)
		cout << "4";

	return 0;
}