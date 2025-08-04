class Solution {
public:
    int bestClosingTime(string customers) {
        int totalY = count(customers.begin(), customers.end(), 'Y');
        int penalty = totalY;
        int minPenalty = penalty;
        int bestHour = 0;

        for (int i = 0; i < customers.size(); ++i) {
            if (customers[i] == 'Y') penalty--;
            else penalty++;
            
            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i + 1;
            }
        }

        return bestHour;
    }
};
;