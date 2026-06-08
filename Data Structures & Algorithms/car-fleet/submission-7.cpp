class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int len = position.size();
        vector<pair<int, int>> sortedPos; 
        // Entering values in vector of pairs
        for (int i = 0; i < len; i++)
            sortedPos.push_back(make_pair(position[i], speed[i]));

        // using modified sort() function to sort
        sort(sortedPos.rbegin(), sortedPos.rend());
        stack<float> fleets;
        for (int j = 0; j < len; j++)
        {   
            float time = static_cast<float>(target - sortedPos[j].first) / sortedPos[j].second;
            if (fleets.empty() || time > fleets.top())
                fleets.push(time);

        }

        return fleets.size();
    }
};
