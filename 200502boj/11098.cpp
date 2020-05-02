/**
*	BOJ
*	No.11098	√øΩ√∏¶ µµøÕ¡‡!
*	@author	peter9378
*	@date		2020.05.02
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

	int n;
	cin >> n;

	while (n--)
	{
		int p;
		cin >> p;

		string answer;
		int current;
		cin >> current >> answer;

		for (int i = 1; i < p; i++)
		{
			int salary;
			string name;

			cin >> salary >> name;
			if (salary > current)
			{
				answer = name;
				current = salary;
			}
		}
		cout << answer << "\n";
	}

	return 0;
}