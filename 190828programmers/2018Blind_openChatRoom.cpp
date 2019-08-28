/**
*	Programmers
*	2018 KAKAO BLIND RECRUIMTMENT#1	오픈채팅방
*	@author	peter9378
*	@date		2019.08.28
*/
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<pair<string, string>> temp;
	set<string> id_set;

	for (int i = 0; i < record.size(); i++)
	{
		string s = record[i];
		string command, id, name;
		// parsing
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == ' ')
			{
				command = s.substr(0, j);
				s = s.substr(j + 1);
				break;
			}
		}
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == ' ')
			{
				id = s.substr(0, j);
				name = s.substr(j + 1);
				break;
			}
		}

		if (command == "Leave")
		{
			id = s;
			for (int j = 0; j < temp.size(); j++)
			{
				if (temp[j].second == id)
				{
					name = temp[j].first.substr(0, temp[j].first.length() - 1);
					break;
				}
			}
		}

		// already id exist
		if (id_set.find(id) != id_set.end())
		{
			if (command == "Enter")
			{
				// change history
				for (int i = 0; i < temp.size(); i++)
				{
					if (temp[i].second == id)
						temp[i].first = name + temp[i].first.back();
				}
				temp.push_back(make_pair(name + '0', id));
			}
			else if (command == "Change")
			{
				// change history
				for (int i = 0; i < temp.size(); i++)
				{
					if (temp[i].second == id)
						temp[i].first = name + temp[i].first.back();
				}
			}
			else if (command == "Leave")
				temp.push_back(make_pair(name + '1', id));
		}
		else    // new id
		{
			id_set.insert(id);
			char cmd = '0';
			if (command == "Leave")
				cmd = '1';
			else if (command == "Change")
				cmd = '2';
			temp.push_back(make_pair(name + cmd, id));
		}
	}

	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].first.back() == '0')
			answer.push_back(temp[i].first.substr(0, temp[i].first.length() - 1) + "님이 들어왔습니다.");
		else if (temp[i].first.back() == '1')
			answer.push_back(temp[i].first.substr(0, temp[i].first.length() - 1) + "님이 나갔습니다.");
	}

	return answer;
}