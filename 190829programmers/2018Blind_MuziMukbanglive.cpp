/**
*	Programmers
*	2018 KAKAO BLIND RECRUIMTMENT#1	무지의 먹방 라이브
*	@author	peter9378
*	@date		2019.08.29
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> food_times, long long k) {
	long long index = 0;
	int length = food_times.size();
	for (long long i = 0; i < k; i++)
	{
		food_times[index]--;
		long long count = 1;
		while (true)
		{
			if (count > length)
				return -1;
			if (food_times[(index + count) % length])
			{
				index = (index + count) % length;
				break;
			}
			count++;
		}
	}
	return index + 1;
}