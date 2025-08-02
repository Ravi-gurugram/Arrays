class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
        queue<tuple<int, int, int, int>> q;  // x, y, steps, remaining_k
        
        q.push({0, 0, 0, k});
        visited[0][0][k] = true;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [x, y, steps, rem_k] = q.front(); q.pop();

            if (x == m - 1 && y == n - 1) return steps;

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int new_k = rem_k - grid[nx][ny];

                    if (new_k >= 0 && !visited[nx][ny][new_k]) {
                        visited[nx][ny][new_k] = true;
                        q.push({nx, ny, steps + 1, new_k});
                    }
                }
            }
        }

        return -1;  // No path found
    }
};
