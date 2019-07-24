#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> v;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		// first: radius, second: index
		v.push_back(make_pair(temp, i));
	}

	sort(v.begin(), v.end(), compare);

	int index = v[v.size() - 1].second;
	bool flag = true;
	for (int i = v.size()-2; i >=0 ; i--)
	{
		temp = v[i].second;
		if (temp > index)
		{
			temp--;
			while (temp != index)
			{
				if (v[temp-1].first)
				{
					i = -1;
					cout << "NO";
					flag = false;
					break;
				}
				temp--;
			}
			if(flag)
				v[v[i].second-1].first = 0;
		}
		else
		{
			temp++;
			while (temp != index)
			{
				if (v[temp+1].first)
				{
					i = -1;
					cout << "NO";
					flag = false;
					break;
				}
				temp++;
			}
			if (flag)
				v[v[i].second+1].first = 0;
		}
	}
	if (flag)
		cout << "YES";

	return 0;
}