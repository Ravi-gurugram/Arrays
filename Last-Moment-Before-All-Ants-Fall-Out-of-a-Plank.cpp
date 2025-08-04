class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxTime = 0;

        for (int pos : left)
            maxTime = max(maxTime, pos); // time to fall = position

        for (int pos : right)
            maxTime = max(maxTime, n - pos); // time to fall = n - position

        return maxTime;
    }
};
