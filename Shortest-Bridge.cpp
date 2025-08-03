class Solution {
public:
    int n;
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int,int>>& q) {
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1) return;

        grid[i][j] = -1; // Mark visited first island
        q.push({i,j});
        for (auto &dir : directions)
            dfs(grid, i + dir[0], j + dir[1], q);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        queue<pair<int,int>> q;

        // Step 1: Find and mark the first island
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, q);
                    found = true;
                }
            }
        }

        // Step 2: BFS to reach the second island
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front(); q.pop();
                for (auto &dir : directions) {
                    int nx = x + dir[0], ny = y + dir[1];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                        if (grid[nx][ny] == 1) return level; // reached 2nd island
                        if (grid[nx][ny] == 0) {
                            grid[nx][ny] = -1; // mark visited water
                            q.push({nx, ny});
                        }
                    }
                }
            }
            level++;
        }
        return -1; // should not reach here
    }
};
