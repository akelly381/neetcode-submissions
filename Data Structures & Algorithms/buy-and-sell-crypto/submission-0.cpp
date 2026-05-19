class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int maxProfit = 0;
        int l = 0, r = 1;
        while (r < len)
        {
            if (prices[l] < prices[r]) {
                int profit = prices[r] - prices[l];
                maxProfit = max(maxProfit, profit);
            }
            else l = r;
            r++;
        }

        return maxProfit;
        
    }
};
