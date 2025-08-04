class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0) return -1;
        if (target == 0) return nums.size();

        int maxLen = -1, left = 0, currSum = 0;

        for (int right = 0; right < nums.size(); ++right) {
            currSum += nums[right];

            while (currSum > target) {
                currSum -= nums[left++];
            }

            if (currSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen == -1 ? -1 : nums.size() - maxLen;
    }
};
