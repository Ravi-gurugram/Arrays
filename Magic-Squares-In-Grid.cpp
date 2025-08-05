class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int row, int col) {
        vector<int> count(10, 0);

        // Check numbers 1 to 9
        for (int i = row; i < row + 3; ++i) {
            for (int j = col; j < col + 3; ++j) {
                int val = grid[i][j];
                if (val < 1 || val > 9 || count[val] > 0)
                    return false;
                count[val]++;
            }
        }

        // Check rows
        for (int i = 0; i < 3; ++i) {
            int sum = grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2];
            if (sum != 15) return false;
        }

        // Check columns
        for (int j = 0; j < 3; ++j) {
            int sum = grid[row][col + j] + grid[row + 1][col + j] + grid[row + 2][col + j];
            if (sum != 15) return false;
        }

        // Check diagonals
        int diag1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int diag2 = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];

        return diag1 == 15 && diag2 == 15;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        for (int i = 0; i <= m - 3; ++i) {
            for (int j = 0; j <= n - 3; ++j) {
                if (grid[i+1][j+1] == 5 && isMagic(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};
