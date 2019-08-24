/**
*	Programmers
*	2017 KAKAO BLIND RECRUIMTMENT#3	n진수 게임
*	@author	peter9378
*	@date		2019.08.25
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string base_plus(string s, int base)
{
	reverse(s.begin(), s.end());
	s[0]++;
	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == base + 48)
		{
			s[i] = '0';
			s[i + 1]++;
		}
	}
	if (s[s.length() - 1] == base + 48)
	{
		s[s.length() - 1] = '0';
		s += '1';
	}
	reverse(s.begin(), s.end());
	return s;
}

string base_plus2(string s, int base)
{
	reverse(s.begin(), s.end());
	if (s[0] == '9')
		s[0] = 'A';
	else
		s[0]++;

	switch (base)
	{
	case 11:
		base = 'B';
		break;
	case 12:
		base = 'C';
		break;
	case 13:
		base = 'D';
		break;
	case 14:
		base = 'E';
		break;
	case 15:
		base = 'F';
		break;
	case 16:
		base = 'G';
		break;
	}

	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == base)
		{
			s[i] = '0';
			if (s[i + 1] == '9')
				s[i + 1] = 'A';
			else
				s[i + 1]++;
		}
	}
	if (s[s.length() - 1] == base)
	{
		s[s.length() - 1] = '0';
		s += '1';
	}
	reverse(s.begin(), s.end());
	return s;
}

string solution(int n, int t, int m, int p) {
	string answer = "";

	string s = "0";
	int count = 0;
	int index = 0;
	bool flag = true;
	while (flag)
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (index%m == p - 1)
			{
				count++;
				answer += s[i];
				if (count == t)
				{
					flag = false;
					break;
				}
			}
			index++;
		}

		// increment
		if (n > 10)
			s = base_plus2(s, n);
		else
			s = base_plus(s, n);
	}


	return answer;
}