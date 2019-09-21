#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;

	deque<int> d;
	for (int i = 0; i < operations.size(); i++)
	{
		if (operations[i] == "D 1")
		{
			if (!d.empty())
				d.pop_back();
		}
		else if (operations[i] == "D -1")
		{
			if (!d.empty())
				d.pop_front();
		}
		else
		{
			d.push_back(stoi(operations[i].substr(2)));
			sort(d.begin(), d.end());
		}
	}

	if (d.empty())
	{
		answer.push_back(0);
		answer.push_back(0);
	}
	else
	{
		answer.push_back(d.back());
		answer.push_back(d.front());
	}

	return answer;
}