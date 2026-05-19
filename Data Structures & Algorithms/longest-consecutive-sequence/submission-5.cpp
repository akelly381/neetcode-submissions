class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.empty()) return 0;

        std::unordered_set<int> hashSet(nums.begin(), nums.end());
        int maxLen = 0;


        for (const auto& elem : hashSet)
        {
            int seqLen = 1;
            int num = elem;
            if (!hashSet.contains(num - 1))
            {
                // Start sequence
                while (hashSet.contains(num+1))
                {
                    seqLen ++;
                    num++;
                }

                maxLen = std::max(maxLen, seqLen);
            }
        }

        return maxLen;
    }
};
