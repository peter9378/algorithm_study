/**
*	baekjoon online judge
*	No. 14891	톱니바퀴
*	@author	peter9378
*	@date		2019.03.14
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// turn functions
void turn_left(vector<int> &v)
{
	v.push_back(v.at(0));
	v.erase(v.begin());
}

void turn_right(vector<int> &v)
{
	v.insert(v.begin(), v.back());
	v.pop_back();
}

void turn(vector<int> &v, int lr)
{
	switch (lr)
	{
	case -1:
		turn_left(v);
		break;
	case 1:
		turn_right(v);
		break;
	}
}

// ctoi
int chartoint(char c)
{
	switch (c)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	vector<vector<int>> v;
	string s;
	for (int i = 0; i < 4; i++)
	{
		cin >> s;
		vector<int> tempv;

		for (int j = 0; j < 8; j++)
			tempv.push_back(chartoint(s[j]));

		v.push_back(tempv);
	}

	int K;
	cin >> K;
	
	// rotate wheels
	for (int i = 0; i < K; i++)
	{
		// input data
		int num, lr;
		cin >> num >> lr;

		// 1: just check right wheels 4: just check left wheels 2,3: check both side wheels
		int origin = num;
		bool flag = true;
		switch (num)
		{
		case 1:
			// check right wheels
			while (num<4 && (v.at(num - 1).at(2) != v.at(num).at(6) ))
				num++;

			// rotate origin wheel first
			turn(v.at(origin-1), lr);

			// rotate remain wheel that rotate together
			for (int j = origin; j < num; j++)
			{
				if (flag)
					turn(v.at(j), -lr);
				else
					turn(v.at(j), lr);
				// change flag for rotate direction
				flag = !flag;
			}
			break;
		case 4:
			// check left wheels
			while (num>1 && (v.at(num - 2).at(2) != v.at(num - 1).at(6)))
				num--;

			// rotate origin wheel first
			turn(v.at(origin - 1), lr);

			// rotate remain wheel that rotate together
			for (int j = origin - 1; j >= num; j--)
			{
				if (flag)
					turn(v.at(j - 1), -lr);
				else
					turn(v.at(j - 1), lr);
				// change flag for rotate direction
				flag = !flag;
			}
			break;
		default:
			// check both side together
			while (num>1 && (v.at(num - 2).at(2) != v.at(num - 1).at(6)) )
				num--;

			for (int j = origin - 1; j >= num; j--)
			{
				if (flag)
					turn(v.at(j - 1), -lr);
				else
					turn(v.at(j - 1), lr);
				flag = !flag;
			}

			num = origin;
			while (num<4 && (v.at(num - 1).at(2) != v.at(num).at(6)))
				num++;

			flag = true;
			for (int j = origin; j<num; j++)
			{
				if (flag)
					turn(v.at(j), -lr);
				else
					turn(v.at(j), lr);
				flag = !flag;
			}
			turn(v.at(origin - 1), lr);
			break;
		}
	}

	// calculate score
	int answer = 0;
	if (v.at(0).at(0))
		answer += 1;
	if (v.at(1).at(0))
		answer += 2;
	if (v.at(2).at(0))
		answer += 4;
	if (v.at(3).at(0))
		answer += 8;
	
	// print answer
	cout << answer;
	return 0;
}
