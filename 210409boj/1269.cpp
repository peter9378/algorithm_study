/**
*	BOJ
*	No.1269	대칭 차집합
*	@author	peter9378
*	@date		2021.04.09
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

	int A, B;
	cin >> A >> B;

	unordered_set<int> s;
	for (int i = 0; i < A; i++)
	{
		int temp;
		cin >> temp;
		s.insert(temp);
	}

	for (int i = 0; i < B; i++)
	{
		int temp;
		cin >> temp;

		if (s.count(temp))
			s.erase(temp);
		else
			s.insert(temp);
	}

	cout << s.size();

	return 0;
}
