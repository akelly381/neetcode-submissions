class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size(); // always 9
        int cols = board[0].size(); // always 9
        // Add all entries to hash maps for easy lookup
        std::unordered_map<int, std::unordered_set<char>> rowMap, colMap, boxMap;
        // Iterate through each row
        for (int r = 0; r < rows; r++)
        {
            // Iterate through each column
            for (int c = 0; c < cols; c++)
            {
                char val = board[r][c];

                if (val == '.') continue;
                int b = boxIdx(r,c);

                // Check if we already have this value in the set
                if (rowMap[r].contains(val) || colMap[c].contains(val) || 
                    boxMap[b].contains(val)) return false;

                rowMap[r].insert(val);
                colMap[c].insert(val);
                boxMap[b].insert(val);
               
            }
        }

        return true;
    }

    int boxIdx(int r, int c)
    {
        return ((r / 3) * 3 + (c / 3));
    }
};
