class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> result(len, 0);
        stack<int> st;

        // add indexes in decreasing order
        for (int i = 0; i < len; i++)
        {
            while (!st.empty())
            {
                int top = st.top();
                if (temperatures[top] < temperatures[i]) {
                    st.pop();
                    result[top] = i - top;
                }
                else break;
            }
            st.push(i);
        }

        return result;

    }
};
