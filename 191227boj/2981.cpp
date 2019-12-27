/**
*	BOJ
*	No.2981	°Ë¹®
*	@author	peter9378
*	@date		2019.12.27
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

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int g = v[1] - v[0];
	for (int i = 2; i < N; i++)
		g = gcd(g, v[i] - v[i - 1]);

	vector<int> answer;
	for (int i = 2; i*i <= g; i++)
	{
		if (g%i == 0)
		{
			answer.push_back(i);
			answer.push_back(g / i);
		}
	}

	answer.push_back(g);
	sort(answer.begin(), answer.end());

	set<int> s;
	for (int i = 0; i < answer.size(); i++)
		s.insert(answer[i]);

	for (auto iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << " ";

	return 0;
}
