class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long currentTime = 0;
        long long totalWait = 0;

        for (auto& c : customers) {
            int arrival = c[0];
            int prep = c[1];

            currentTime = max(currentTime, (long long)arrival);
            currentTime += prep;

            totalWait += (currentTime - arrival);
        }

        return (double)totalWait / customers.size();
    }
};
