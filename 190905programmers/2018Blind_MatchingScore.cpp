/**
*	Programmers
*	2018 KAKAO BLIND RECRUIMTMENT#1	매칭 점수
*	@author	peter9378
*	@date		2019.09.05
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct page {
	int index, basic;
	string link;
	vector<string> ext;
	double score = 0;

	page(int a, int b, string c, vector<string> d, double e) {
		this->index = a;
		this->basic = b;
		this->link = c;
		this->ext = d;
		this->score = e;
	}
};

string low(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] > 64 && s[i] < 91)
			s[i] += 32;
	}
	return s;
}

int solution(string word, vector<string> pages) {
	int answer = 0;
	vector<page> v;
	word = low(word);

	// parse
	for (int i = 0; i < pages.size(); i++)
	{
		pages[i] = low(pages[i]);

		int basic = 0;
		for (int j = 0; j < pages[i].length(); j++)
		{
			int id = 0;
			while (pages[i][j + id] == word[id])
			{
				id++;
			}
			if (id == word.length())
			{
				if (pages[i][j - 1] > 96 && pages[i][j - 1] < 123)
				{
					j += id;
					continue;
				}
				if (pages[i][j + id] > 96 && pages[i][j + id] < 123)
				{
					j += id;
					continue;
				}
				basic++;
			}
		}

		string url = "";
		int index = pages[i].find("meta property=\"og:url\" content");
		if (index != string::npos)
		{
			index += 30;
			while (pages[i][index] != '"')
				index++;
			index++;
			while (pages[i][index] != '"')
				url += pages[i][index++];
			if (url[0] != 'h')
				return 6;
		}
		pages[i] = pages[i].substr(pages[i].find("<body>"));
		vector<string> external_url;
		while (true)
		{
			index = pages[i].find("a href");
			if (index == string::npos)
				break;
			index += 7;
			while (pages[i][index] != '"')
				index++;
			index++;
			string url = "";
			while (pages[i][index] != '"')
				url += pages[i][index++];
			external_url.push_back(url);
			pages[i] = pages[i].substr(index);
		}
		v.push_back(page{ i, basic, url, external_url, 0 });
	}

	for (int i = 0; i < v.size(); i++)
	{
		double temp = 0;
		for (int j = 0; j < v.size(); j++)
		{
			if (i == j)
				continue;
			for (int k = 0; k < v[j].ext.size(); k++)
			{
				if (v[i].link == v[j].ext[k])
					temp += (double)v[j].basic / v[j].ext.size();
			}
		}
		v[i].score = v[i].basic + temp;
	}

	double max = -1;
	for (int i = 0; i < v.size(); i++)
	{
		if (max < v[i].score)
		{
			max = v[i].score;
			answer = v[i].index;
		}
	}


	return answer;
}