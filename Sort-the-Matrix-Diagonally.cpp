class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> diagMap;

        // Step 1: Store all elements of each diagonal in a min-heap
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                diagMap[i - j].push(mat[i][j]);

        // Step 2: Replace each matrix element with the sorted value from the heap
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                mat[i][j] = diagMap[i - j].top();
                diagMap[i - j].pop();
            }

        return mat;
    }
};
