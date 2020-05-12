/**
*	BOJ
*	No.2776	¾Ï±â¿Õ
*	@author	peter9378
*	@date		2020.05.12
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

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		unordered_set<int> s;
		for (int i = 0; i < N; i++)
		{
			int temp;
			cin >> temp;
			s.insert(temp);
		}

		int M;
		cin >> M;

		for (int i = 0; i < M; i++)
		{
			int temp;
			cin >> temp;
			cout << (s.find(temp) != s.end()) << "\n";
		}
	}

	return 0;
}