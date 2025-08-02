class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mod_map;
        mod_map[0] = -1;  // important for subarrays starting at index 0
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (k != 0)
                sum %= k;

            if (mod_map.find(sum) != mod_map.end()) {
                if (i - mod_map[sum] >= 2)
                    return true;
            } else {
                mod_map[sum] = i;  // store only first occurrence
            }
        }
        return false;
    }
};
