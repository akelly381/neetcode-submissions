class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        std::map<vector<char>, vector<string>> letterMap;

        // Iterate through strs
        for (string s : strs)
        {
            vector<char> abc(26, 0);
            // Count the characters
            for (char c : s)
            {
                abc[c - 'a'] += 1;
            }
            // Add letter count, string to hash map
            letterMap[abc].push_back(s);
        }

        // Finally, add all values in hash map to answer
        for (const auto& pair : letterMap)
        {
            answer.push_back(pair.second);
        }

        return answer;
    }
};
