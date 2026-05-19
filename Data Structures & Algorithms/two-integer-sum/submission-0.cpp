class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> diffMap;
        int diff;
        std::vector<int> answer;

        for (int i = 0; i < nums.size(); i++)
        {
            diff = target - nums[i];
            if (diffMap.count(diff)) {
                auto search = diffMap.find(diff);
                if (search != diffMap.end()) {
                    answer.push_back(search->second);
                    answer.push_back(i);
                }
            }
            diffMap[nums[i]] = i;
        }

        return answer;
        
    }
};
