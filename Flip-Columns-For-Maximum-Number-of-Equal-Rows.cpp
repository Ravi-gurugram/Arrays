class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;
        
        for (auto& row : matrix) {
            string pattern = "";
            int first = row[0];
            
            for (int bit : row) {
                pattern += (bit ^ first) + '0';  // normalize using XOR with first bit
            }

            mp[pattern]++;
        }
        
        int maxRows = 0;
        for (auto& [_, count] : mp) {
            maxRows = max(maxRows, count);
        }
        
        return maxRows;
    }
};
