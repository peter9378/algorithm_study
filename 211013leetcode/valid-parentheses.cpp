class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto i : s) {
            if (i == '(')
                stk.push(i);
            else if (i == '{')
                stk.push(i);
            else if (i == '[')
                stk.push(i);
            else if (i == ')') {
                if (stk.empty() || stk.top() != '(')
                    return false;
                stk.pop();
            }
            else if (i == '}') {
                if (stk.empty() || stk.top() != '{')
                    return false;
                stk.pop();
            }
            else if (i == ']') {
                if (stk.empty() || stk.top() != '[')
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
