#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check[51];
int answer = 999999999;

bool promise(string a, string b)
{
	int cnt = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != b[i])
			cnt++;
	}
	if (cnt == 1)
		return true;
	return false;
}

void dfs(int counting, string now, string target, vector<string> v)
{
	if (now == target)
	{
		answer = min(counting, answer);
		return;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (check[i])
			continue;
		if (promise(now, v[i]))
		{
			check[i] = true;
			dfs(counting + 1, v[i], target, v);
			check[i] = false;
		}
	}
	return;
}

int solution(string begin, string target, vector<string> words) {
	if (find(words.begin(), words.end(), target) == words.end())
		return 0;

	sort(words.begin(), words.end());

	dfs(0, begin, target, words);

	return answer;
}