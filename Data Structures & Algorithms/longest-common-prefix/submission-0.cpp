class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";

        string prefix = strs[0]; // dance
        for (int i = 1; i < strs.size(); i++)
        {   
            while (prefix.length() > 0) { 
                if (strs[i].find(prefix) != 0) 
                {
                    prefix.pop_back();
                }
                else break;
            }   
        }
        return prefix;
    }
};