class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[1] < b[1]; // sort by end time
        });
        
        int end = INT_MIN, count = 0;
        for (auto &interval : intervals) {
            if (interval[0] >= end) {
                end = interval[1]; // no overlap
            } else {
                count++; // overlap, remove it
            }
        }
        return count;
    }
};
