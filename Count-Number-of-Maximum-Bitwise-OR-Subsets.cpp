class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int num : nums) {
            maxOr |= num;  // Find the maximum possible OR
        }

        int count = 0;
        dfs(nums, 0, 0, maxOr, count);
        return count;
    }

    void dfs(const vector<int>& nums, int index, int currentOr, int maxOr, int& count) {
        if (index == nums.size()) {
            if (currentOr == maxOr) {
                count++;
            }
            return;
        }

        // Include nums[index]
        dfs(nums, index + 1, currentOr | nums[index], maxOr, count);

        // Exclude nums[index]
        dfs(nums, index + 1, currentOr, maxOr, count);
    }
};
