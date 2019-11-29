/**
*	BOJ
*	No.10815	숫자 카드
*	@author	peter9378
*	@date		2019.11.29
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

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

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
		if (s.find(temp) == s.end())
			cout << "0 ";
		else
			cout << "1 ";
	}

	return 0;
}
