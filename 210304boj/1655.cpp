/**
*	BOJ
*	No.1655	가운데를 말해요
*	@author	peter9378
*	@date		2021.03.04
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

	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int> > min_heap;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (max_heap.size() == min_heap.size())
			max_heap.push(num);
		else
			min_heap.push(num);

		if (!min_heap.empty() && !max_heap.empty() && min_heap.top() < max_heap.top())
		{
			int a = max_heap.top();
			int b = min_heap.top();
			max_heap.pop();
			min_heap.pop();
			max_heap.push(b);
			min_heap.push(a);
		}

		cout << max_heap.top() << "\n";
	}

	return 0;
}
