class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) 
            parent[x] = find(parent, parent[x]);
        return parent[x];
    }
    
    void unite(vector<int>& parent, int x, int y) {
        int px = find(parent, x);
        int py = find(parent, y);
        if (px != py)
            parent[px] = py;
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int total = n * n * 4;  // 4 parts per cell
        vector<int> parent(total);
        
        for (int i = 0; i < total; ++i)
            parent[i] = i;
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                int base = 4 * (r * n + c);
                char ch = grid[r][c];
                
                // Inside the cell
                if (ch == '/') {
                    unite(parent, base + 0, base + 3);
                    unite(parent, base + 1, base + 2);
                } else if (ch == '\\') {
                    unite(parent, base + 0, base + 1);
                    unite(parent, base + 2, base + 3);
                } else {
                    unite(parent, base + 0, base + 1);
                    unite(parent, base + 1, base + 2);
                    unite(parent, base + 2, base + 3);
                }

                // Downward neighbor
                if (r + 1 < n) {
                    int bottom = 4 * ((r + 1) * n + c);
                    unite(parent, base + 2, bottom + 0);
                }

                // Rightward neighbor
                if (c + 1 < n) {
                    int right = 4 * (r * n + (c + 1));
                    unite(parent, base + 1, right + 3);
                }
            }
        }

        // Count unique parents
        unordered_set<int> regions;
        for (int i = 0; i < total; ++i) {
            regions.insert(find(parent, i));
        }
        return regions.size();
    }
};
