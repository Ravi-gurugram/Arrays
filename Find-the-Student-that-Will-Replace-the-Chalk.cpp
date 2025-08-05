class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long long> prefix(n);
        
        prefix[0] = chalk[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + chalk[i];
        }

        k %= prefix[n - 1];

        // Binary search to find the first index where prefix[i] > k
        int left = 0, right = n - 1, ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (prefix[mid] > k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
