class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> sizeMap;
        vector<vector<int>> result;

        for (int i = 0; i < groupSizes.size(); ++i) {
            int size = groupSizes[i];
            sizeMap[size].push_back(i);
            if (sizeMap[size].size() == size) {
                result.push_back(sizeMap[size]);
                sizeMap[size].clear();
            }
        }

        return result;
    }
};
