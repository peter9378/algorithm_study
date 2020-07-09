/**
*	BOJ
*	No.17219	비밀번호 찾기
*	@author	peter9378
*	@date		2020.07.09
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
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	unordered_map<string, string> m;
	for (int i = 0; i < N; i++)
	{
		string a, b;
		cin >> a >> b;
		m[a] = b;
	}

	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		cout << m[s] << "\n";
	}

	return 0;
}