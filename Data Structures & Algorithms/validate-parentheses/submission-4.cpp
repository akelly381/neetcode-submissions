class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        for (char c : s)
        {
            // add open brackets to stack
            if (c == '{' || c == '[' || c == '(')
                stck.push(c);
            else 
            {
                if (stck.empty()) return false;
                char top = stck.top();
                if ((top == '{' && c == '}') || 
                    (top == '(' && c == ')') || 
                    (top == '[' && c == ']'))
                {
                    stck.pop();
                }
                else return false;
            }   
        }
        if (stck.empty()) return true;
        else return false;
    }
};
