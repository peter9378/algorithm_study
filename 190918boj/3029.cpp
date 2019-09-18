/**
*	BOJ
*	No.3028	창영마을
*	@author	peter9378
*	@date		2019.09.18
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;


// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int h = stoi(s.substr(0, 2));
	int m = stoi(s.substr(3, 2));
	int ss = stoi(s.substr(6, 2));
	int ptime = h * 3600 + m * 60 + ss;

	cin >> s;
	h = stoi(s.substr(0, 2));
	m = stoi(s.substr(3, 2));
	ss = stoi(s.substr(6, 2));
	int ntime = h * 3600 + m * 60 + ss;

	if (ntime == ptime)
		cout << "24:00:00";
	else if (ntime - ptime > 86400)
		cout << "24:00:00";
	else
	{
		if (ntime < ptime)
			ntime += 86400;
		ntime -= ptime;

		h = ntime / 3600;
		m = (ntime % 3600) / 60;
		ss = ntime % 60;

		if (h < 10)
			cout << "0" << h << ":";
		else
			cout << h << ":";
		if (m < 10)
			cout << "0" << m << ":";
		else
			cout << m << ":";
		if (ss < 10)
			cout << "0" << ss;
		else
			cout << ss;
	}

	return 0;
}