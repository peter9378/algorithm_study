/**
*	BOJ
*	No.11729	하노이 탑 이동 순서
*	@author	peter9378
*	@date		2019.08.18
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> v;

void hanoi(int number, int from, int through, int to)
{
	if (number == 1)
		v.push_back(make_pair(from, to));
	else
	{
		hanoi(number - 1, from, to, through);
		v.push_back(make_pair(from, to));
		hanoi(number - 1, through, from, to);
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	hanoi(N, 1, 2, 3);

	// print answer
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << "\n";	

	return 0;
}