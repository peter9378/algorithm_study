/**
*	BOJ
*	No. 11723	집합
*	@author	peter9378
*	@date		2019.08.04
*/
#include <iostream>
#include <string>
using namespace std;


bool arr[21];

void add(int x)
{
	arr[x] = true;
	return;
}

void remove(int x)
{
	if (arr[x])
		arr[x] = false;
	return;
}

void check(int x)
{
	if (arr[x])
		cout << "1\n";
	else
		cout << "0\n";
	return;
}

void toggle(int x)
{
	if (arr[x])
		arr[x] = false;
	else
		arr[x] = true;
	return;
}

void all()
{
	for (int i = 1; i < 21; i++)
		arr[i] = true;
	return;
}

void empty()
{
	for (int i = 1; i < 21; i++)
		arr[i] = false;
	return;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M;
	cin >> M;

	while (M--)
	{
		string s;
		int n;
		cin >> s;
		if (s == "all")
		{
			all();
			continue;
		}
		else if (s == "empty")
		{
			empty();
			continue;
		}
		cin >> n;

		if (s == "add")
			add(n);
		else if (s == "remove")
			remove(n);
		else if (s == "check")
			check(n);
		else if (s == "toggle")
			toggle(n);
	}
	return 0;
}