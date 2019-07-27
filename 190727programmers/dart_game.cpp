/**
*	BOJ
*	다트 게임
*	@author	peter9378
*	@date		2019.07.27
*/
#include <string>
#include <vector>

using namespace std;

int arr[11];
vector<int> v;
vector<int> vv;

int pow(int n, char c)
{
	int result = 1;
	int p = 0;
	switch (c)
	{
	case 'T':
		p++;
	case 'D':
		p++;
	case 'S':
		p++;
	}
	while (p--)
		result *= n;
	return result;
}

int solution(string dartResult) {
	int answer = 0;
	int index = 0;
	for (int i = 0; i < dartResult.length(); i++)
	{
		if (dartResult[i] == '*')
		{
			if (index == 1)
				v.push_back(0);
			else
			{
				v.push_back(index - 2);
				v.push_back(index - 1);
			}
		}
		else if (dartResult[i] == '#')
			vv.push_back(index - 1);
		else
		{
			if (dartResult[i] == '1')
			{
				if (dartResult[i + 1] == '0')
				{
					arr[index] = pow(10, dartResult[i + 2]);
					index++;
					i += 2;
				}
				else
				{
					arr[index] = pow(1, dartResult[i + 1]);
					index++;
					i++;
				}
			}
			else
			{
				arr[index] = pow(dartResult[i] - 48, dartResult[i + 1]);
				index++;
				i++;
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
		arr[v[i]] *= 2;
	for (int i = 0; i < vv.size(); i++)
		arr[vv[i]] *= -1;
	for (int i = 0; i < index; i++)
		answer += arr[i];

	return answer;
}