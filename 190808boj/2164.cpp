/**
*	BOJ
*	No.2164	카드2
*	@author	peter9378
*	@date		2019.0808
*/
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	deque<int> d;
	for (int i = 0; i < N; i++)
		d.push_back(i + 1);

	while (d.size() != 1)
	{
		d.pop_front();
		d.push_back(d[0]);
		d.pop_front();
	}

	cout << d[0];

	return 0;
}