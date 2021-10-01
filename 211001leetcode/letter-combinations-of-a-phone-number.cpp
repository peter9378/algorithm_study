class Solution {
public:
    vector<string> letterCombinations(string digits) {        
        vector<string> answer;
        if(digits.size() == 0)
            return answer;
        
        string temp;
        vector<vector<char>> cube;
        cube.push_back(vector<char>{});
        cube.push_back(vector<char>{});
        cube.push_back(vector<char>{'a', 'b', 'c'}); // 2
        cube.push_back(vector<char>{'d', 'e', 'f'});
        cube.push_back(vector<char>{'g', 'h', 'i'});
        cube.push_back(vector<char>{'j', 'k', 'l'});
        cube.push_back(vector<char>{'m', 'n', 'o'});
        cube.push_back(vector<char>{'p', 'q', 'r', 's'});
        cube.push_back(vector<char>{'t', 'u', 'v'});
        cube.push_back(vector<char>{'w', 'x', 'y', 'z'});
        cube.push_back(vector<char>()); // 9
        
        dfs(cube, answer, temp, 0, digits);
        return answer;
    }
    
    void dfs(const vector<vector<char>>& cube, vector<string>& answer, string& temp, int index, const string& digits) {
        if(index == digits.size())
            answer.push_back(temp);
        else
        {
            for(int i = 0; i < cube[digits[index]-'0'].size(); i++) {
                temp.push_back(cube[digits[index]-'0'][i]);
                dfs(cube, answer, temp, index+1, digits);
                temp.pop_back();
            }
        }
    }
};
