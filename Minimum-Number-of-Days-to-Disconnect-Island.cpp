class Solution {
public:
    int n, m;
    
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if (i < 0 || i >= n || j < 0 || j >= m ||
            grid[i][j] == 0 || visited[i][j])
            return;
        
        visited[i][j] = true;
        
        dfs(grid, i+1, j, visited);
        dfs(grid, i-1, j, visited);
        dfs(grid, i, j+1, visited);
        dfs(grid, i, j-1, visited);
    }
    
    int countIslands(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    dfs(grid, i, j, visited);
                    count++;
                }
            }
        }
        
        return count;
    }
    
    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        // Check if already disconnected
        if (countIslands(grid) != 1)
            return 0;

        // Try removing each cell
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0; // remove land
                    if (countIslands(grid) != 1)
                        return 1;
                    grid[i][j] = 1; // revert
                }
            }
        }
        
        return 2; // if no single cell removal works
    }
};
