/**
*	Programmers
*	2017 KAKAO BLIND RECRUIMTMENT#3	압축
*	@author	peter9378
*	@date		2019.08.25
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;
	vector<string> dic;
	dic.push_back("");
	dic.push_back("A");
	dic.push_back("B");
	dic.push_back("C");
	dic.push_back("D");
	dic.push_back("E");
	dic.push_back("F");
	dic.push_back("G");
	dic.push_back("H");
	dic.push_back("I");
	dic.push_back("J");
	dic.push_back("K");
	dic.push_back("L");
	dic.push_back("M");
	dic.push_back("N");
	dic.push_back("O");
	dic.push_back("P");
	dic.push_back("Q");
	dic.push_back("R");
	dic.push_back("S");
	dic.push_back("T");
	dic.push_back("U");
	dic.push_back("V");
	dic.push_back("W");
	dic.push_back("X");
	dic.push_back("Y");
	dic.push_back("Z");

	int count = 1;
	for (int i = 0; i < msg.length(); i += count - 1)
	{
		count = 1;
		string target = msg.substr(i, count);
		while (find(dic.begin(), dic.end(), target) != dic.end())
		{
			count++;
			target = msg.substr(i, count);
			if (i + count > msg.length())
				break;
		}
		dic.push_back(target);
		target = msg.substr(i, count - 1);
		for (int k = 1; k < dic.size(); k++)
		{
			if (dic[k] == target)
			{
				answer.push_back(k);
				break;
			}
		}
	}

	return answer;
}