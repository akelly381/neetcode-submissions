class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> diffMap;
        int diff;
        std::vector<int> answer;

        for (int i = 0; i < nums.size(); i++)
        {
            // Calculate the difference
            diff = target - nums[i];
            // If the map already has the difference, then we know our two indices
            if (diffMap.count(diff)) {
                auto search = diffMap.find(diff);
                if (search != diffMap.end()) {
                    // Push the index we already found
                    answer.push_back(search->second);
                    // Next is the curr index
                    answer.push_back(i);
                }
            }
            // Insert (nums value, index) to hash table
            diffMap[nums[i]] = i;
        }

        return answer;
        
    }
};
