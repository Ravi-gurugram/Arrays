class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total = 0;
        for (int num : nums) {
            total = (total + num) % p;
        }

        if (total == 0) return 0;  // already divisible

        unordered_map<int, int> prefixMap;
        prefixMap[0] = -1;  // for handling from index 0
        int minLen = n;
        long long prefix = 0;

        for (int i = 0; i < n; ++i) {
            prefix = (prefix + nums[i]) % p;
            int target = (prefix - total + p) % p;

            if (prefixMap.count(target)) {
                minLen = min(minLen, i - prefixMap[target]);
            }

            prefixMap[prefix] = i;
        }

        return (minLen == n) ? -1 : minLen;
    }
};
