class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;

        for (int j = 0; j < n; ++j) {
            int left_smaller = 0, left_greater = 0;
            int right_smaller = 0, right_greater = 0;

            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) left_smaller++;
                else if (rating[i] > rating[j]) left_greater++;
            }

            for (int k = j + 1; k < n; ++k) {
                if (rating[k] > rating[j]) right_greater++;
                else if (rating[k] < rating[j]) right_smaller++;
            }

            count += (left_smaller * right_greater) + (left_greater * right_smaller);
        }

        return count;
    }
};
