/**
*	BOJ
*	No.15596	정수 N개의 합
*	@author	peter9378
*	@date		2019.08.14
*/
#include <vector>

long long sum(std::vector<int> &a)
{
	long long result = 0;
	for (std::vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
		result += *iter;
	return result;
}