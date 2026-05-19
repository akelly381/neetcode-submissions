class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> numCounts;
        // Count frequency of each number
        for (int i : nums)
        {
            numCounts[i] += 1;
        }

        // Create buckets indexed by frequence
        vector<vector<int>> buckets(nums.size() + 1);

        // Iterate through hash map and add number into bucket by frequency
        for (auto& [num, count] : numCounts) {
            buckets[count].push_back(num);
        }

        // Now want to return the max k buckets
        vector<int> result;
        for (int i = buckets.size() - 1; i > 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k)
                    break;
            }
        }

        return result;
    }
};
