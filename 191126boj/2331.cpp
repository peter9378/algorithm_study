/**
*	BOJ
*	No.2331	반복수열
*	@author	peter9378
*	@date		2019.11.26
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

	int A, P;
	cin >> A >> P;

	vector<int> v;
	set<int> s;
	v.push_back(A);
	s.insert(A);

	while (true)
	{
		int temp = 0, target = v.back();
		while (target)
		{
			temp += pow(target % 10, P);
			target /= 10;
		}
		if (s.find(temp) != s.end())
		{
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i] == temp)
				{
					cout << i;
					break;
				}
			}
			break;
		}
		v.push_back(temp);
		s.insert(temp);
	}


	return 0;
}
