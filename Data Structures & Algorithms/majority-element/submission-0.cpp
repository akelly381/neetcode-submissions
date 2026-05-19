class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        int maxCount = 0;
        int maxNum = 0;
        for (int n : nums)
        {
            hashMap[n]++;
            if (hashMap[n] > maxCount) {
                maxCount = hashMap[n];
                maxNum = n;
            }
        }
        return maxNum;  
    }
};