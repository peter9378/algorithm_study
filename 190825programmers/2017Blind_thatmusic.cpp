/**
*	Programmers
*	2017 KAKAO BLIND RECRUIMTMENT#3	방금그곡
*	@author	peter9378
*	@date		2019.08.25
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string convert(string s)
{
	string result = "";
	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i + 1] == '#')
		{
			switch (s[i])
			{
			case 'C':
				result += 'H';
				break;
			case 'D':
				result += 'I';
				break;
			case 'F':
				result += 'J';
				break;
			case 'G':
				result += 'K';
				break;
			case 'A':
				result += 'L';
				break;
			}
			i++;
		}
		else
			result += s[i];
	}
	if (s[s.length() - 1] != '#')
		result += s[s.length() - 1];
	return result;
}

string solution(string m, vector<string> musicinfos) {
	string answer = "";
	int answer_time = -1;

	m = convert(m);

	// parsing musics
	for (int i = 0; i < musicinfos.size(); i++)
	{
		int start_time = stoi(musicinfos[i].substr(0, 2)) * 60 + stoi(musicinfos[i].substr(3, 2));
		int end_time = stoi(musicinfos[i].substr(6, 2)) * 60 + stoi(musicinfos[i].substr(9, 2));
		int time = end_time - start_time;

		string title = "";
		string melody = "";
		for (int j = 12; j < musicinfos[i].length(); j++)
		{
			if (musicinfos[i][j] == ',')
			{
				title = musicinfos[i].substr(12, j - 12);
				melody = convert(musicinfos[i].substr(j + 1));
				break;
			}
		}

		if (time <= melody.length())
		{
			melody = melody.substr(0, time);
			if (melody.find(m) != string::npos)
			{
				if (answer_time < time)
				{
					answer = title;
					answer_time = time;
				}
			}
		}
		else
		{
			string temp = "";
			int len = melody.length();

			for (int i = 0; i < time; i++)
				temp += melody[i%len];

			if (temp.find(m) != string::npos)
			{
				if (answer_time < time)
				{
					answer = title;
					answer_time = time;
				}
			}
		}
	}
	if (answer == "")
		answer = "(None)";
	return answer;
}