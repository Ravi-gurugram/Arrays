class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
        long long sum = n * (n + 1) / 2;
        long long sum_sq = n * (n + 1) * (2 * n + 1) / 6;

        long long actual_sum = 0, actual_sq = 0;
        for (int num : nums) {
            actual_sum += num;
            actual_sq += (long long)num * num;
        }

        long long diff = actual_sum - sum;           // x - y
        long long sq_diff = actual_sq - sum_sq;      // x^2 - y^2

        long long sum_xy = sq_diff / diff;           // x + y

        int x = (diff + sum_xy) / 2;  // duplicate
        int y = x - diff;             // missing

        return {x, y};
    }
};
