class Solution {
public:
	bool detectCapitalUse(string word) {
		long long capital = 0;
		for (auto w : word) {
			if (w >= 'A' && w <= 'Z')
				capital++;
		}
		if (capital == word.length())
			return true;
		else if (capital == 1 && word[0] >= 'A' && word[0] <= 'Z')
			return true;
		else if (capital == 0)
			return true;
		return false;
	}
};