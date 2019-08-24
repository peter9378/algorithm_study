/**
*	Programmers
*	2017 KAKAO BLIND RECRUIMTMENT#3	파일명 정렬
*	@author	peter9378
*	@date		2019.08.25
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	string head;
	string number;
	string tail;
	int index;
};

string lower(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] > 96 && s[i] < 123)
			s[i] -= 32;
	}
	return s;
}

bool compare(const node &a, const node &b)
{
	if (lower(a.head) < lower(b.head))
		return true;
	else if (lower(a.head) > lower(b.head))
		return false;
	if (stoi(a.number) < stoi(b.number))
		return true;
	else if (stoi(a.number) > stoi(b.number))
		return false;
	return a.index < b.index;
}



vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<node> v;
	// parsing
	for (int i = 0; i < files.size(); i++)
	{
		node temp;
		temp.index = i;
		bool head_flag = true;
		int index = 0;
		for (int j = 0; j < files[i].length(); j++)
		{
			if (head_flag)
			{
				if (files[i][j] < 58 && files[i][j] > 47)
				{
					temp.head = files[i].substr(0, j);
					head_flag = false;
					index = j;
				}
			}
			else
			{
				if (files[i][j] > 57 || files[i][j] < 48)
				{
					temp.number = files[i].substr(index, j - index);
					temp.tail = files[i].substr(j);
					break;
				}
			}
		}
		if (temp.number == "")
			temp.number = files[i].substr(index);
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
	{
		string temp = v[i].head;
		temp += v[i].number;
		temp += v[i].tail;
		answer.push_back(temp);
	}

	return answer;
}