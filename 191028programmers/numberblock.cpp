/**
*	Programmers
*	숫자 블록
*	@author	peter9378
*	@date		2019.10.28
*/
#include <string>
#include <vector>

using namespace std;

#define MAX 100001

int arr[MAX] = { 0, 1 };

vector<int> solution(long long begin, long long end) {
	vector<int> answer;

	for (int i = 2; i <= MAX; i++)
	{
		for (int j = 2; i*j <= MAX; j++)
			arr[i*j] = 1;
	}

	vector<int> prime;
	for (int i = 2; i < MAX; i++)
	{
		if (!arr[i])
			prime.push_back(i);
	}

	for (long long i = begin; i <= end; i++)
	{
		bool flag = true;
		for (int j = 0; j < prime.size(); j++)
		{
			if (i%prime[j] == 0)
			{
				answer.push_back(i / prime[j]);
				flag = false;
				break;
			}
		}
		if (flag)
			answer.push_back(1);
	}

	return answer;
}