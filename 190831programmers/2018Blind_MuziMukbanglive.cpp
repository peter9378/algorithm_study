/**
*	Programmers
*	2018 KAKAO BLIND RECRUIMTMENT#1	무지의 먹방 라이브
*	@author	peter9378
*	@date		2019.08.31
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second < b.second;
}


int solution(vector<int> food_times, long long k) {
	long long length = food_times.size();
	long long sum = 0;
	vector<pair<int, int>> v;   // index, value

	for (int i = 0; i < length; i++)
	{
		v.push_back(make_pair(i, food_times[i]));
		sum += food_times[i];
	}

	if (sum <= k)
		return -1;

	sort(v.begin(), v.end(), compare);

	long long count = 0;
	int index = 0;
	while (true)
	{
		long long temp = 0;
		if (index)
			temp = (v[index].second - v[index - 1].second)*(length - index);
		else
			temp = v[index].second*length;

		if (count + temp > k)
		{
			k -= count;
			break;
		}
		count += temp;
		index++;
	}

	vector<int> result;
	for (int i = index; i < length; i++)
		result.push_back(v[i].first + 1);

	sort(result.begin(), result.end());

	return result[k%result.size()];
}