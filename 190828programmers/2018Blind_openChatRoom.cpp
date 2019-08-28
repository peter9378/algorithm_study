/**
*	Programmers
*	2018 KAKAO BLIND RECRUIMTMENT#1	오픈채팅방
*	@author	peter9378
*	@date		2019.08.28
*/
#include <vector>
#include <string>
#include <map>

using namespace std;


vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> m;    // id, name

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

		if (m.find(id) != m.end())
		{
			if (command == "Enter" || command == "Change")
				m[id] = name;
		}
		else
			m[id] = name;
	}

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
			answer.push_back(m[id] + "님이 나갔습니다.");
		}
		else if (command == "Enter")
			answer.push_back(m[id] + "님이 들어왔습니다.");
	}



	return answer;
}