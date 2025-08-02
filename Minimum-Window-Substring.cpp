class Solution {
public:
    string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";

    unordered_map<char, int> t_freq;
    for (char c : t) t_freq[c]++;

    unordered_map<char, int> window;
    int have = 0, need = t_freq.size();

    int left = 0, min_len = INT_MAX, start = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        window[c]++;

        if (t_freq.count(c) && window[c] == t_freq[c]) {
            have++;
        }

        while (have == need) {
            // Try to update the result
            if ((right - left + 1) < min_len) {
                min_len = right - left + 1;
                start = left;
            }

            // Shrink window
            window[s[left]]--;
            if (t_freq.count(s[left]) && window[s[left]] < t_freq[s[left]]) {
                have--;
            }
            left++;
        }
    }

    return min_len == INT_MAX ? "" : s.substr(start, min_len);
}

};