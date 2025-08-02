class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n);

        for (int col = 0; col < n; col++) {
            int curr_col = col;
            for (int row = 0; row < m; row++) {
                int dir = grid[row][curr_col];
                int next_col = curr_col + dir;

                // Check if next column is valid and direction matches
                if (next_col < 0 || next_col >= n || grid[row][next_col] != dir) {
                    curr_col = -1;
                    break;
                }
                curr_col = next_col;
            }
            res[col] = curr_col;
        }

        return res;
    }
};
