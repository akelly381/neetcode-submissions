#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string t : tokens)
        {
            // operator
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                // pop two digits from stack
                if (st.size() >= 2) {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();

                    // evaluate
                    if (t == "+") st.push(a + b);
                    else if (t == "-") st.push(b - a);
                    else if (t == "*") st.push(a * b);
                    else if (t == "/") st.push(b / a);
                }
            }
            // push number onto stack
            else {
                st.push(stoi(t));
            }

        }

        if (!st.empty()) return st.top();
        else return 0;
    }
};
