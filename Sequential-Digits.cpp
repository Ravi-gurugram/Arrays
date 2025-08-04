class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> result;
        
        for (int len = 2; len <= 9; ++len) {
            for (int start = 0; start + len <= 9; ++start) {
                int num = stoi(digits.substr(start, len));
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }

        return result;
    }
};
