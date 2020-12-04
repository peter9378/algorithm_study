/**
*	BOJ
*	No.13323	BOJ ¼ö¿­ 1
*	@author	peter9378
*	@date		2020.12.04
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

	int N;
	cin >> N;

	priority_queue<int> pq;
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		temp -= i;

		pq.push(temp);

		if (!pq.empty() && pq.top() > temp)
		{
			answer += pq.top() - temp;
			pq.pop();
			pq.push(temp);
		}
	}

	cout << answer;

	return 0;
}
