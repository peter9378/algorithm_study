/**
*	Programmers
*	2018 KAKAO BLIND RECRUIMTMENT#1	실패율
*	@author	peter9378
*	@date		2019.08.28
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int counting[505];

bool compare(const pair<int, double> &a, const pair<int, double> &b)
{
	return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	for (int i = 0; i < stages.size(); i++)
		counting[stages[i]]++;

	int temp = stages.size();
	vector<pair<int, double>> v;
	for (int i = 1; i <= N; i++)
	{
		v.push_back(make_pair(i, counting[i] / (double)temp));
		temp -= counting[i];
	}

	stable_sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
		answer.push_back(v[i].first);

	return answer;
}