/**
*	BOJ
*	No.5635	»ıÀÏ
*	@author	peter9378
*	@date		2020.05.08
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

struct student {
	string name;
	int dd, mm, yyyy;
};

bool compare(const student& a, const student& b)
{
	if (a.yyyy < b.yyyy)
		return true;
	else if (a.yyyy == b.yyyy)
	{
		if (a.mm < b.mm)
			return true;
		else if (a.mm == b.mm)
		{
			if (a.dd < b.dd)
				return true;
		}
	}
	return false;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<student> v;
	for (int i = 0; i < n; i++)
	{
		string name;
		int dd, mm, yyyy;
		cin >> name >> dd >> mm >> yyyy;

		v.push_back({ name, dd, mm, yyyy });
	}

	sort(v.begin(), v.end(), compare);

	cout << v.back().name << "\n" << v.front().name;

	return 0;
}