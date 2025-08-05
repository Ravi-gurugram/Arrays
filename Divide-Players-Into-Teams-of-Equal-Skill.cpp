class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());  // Step 1: Sort the skills
        int n = skill.size();
        int target = skill[0] + skill[n - 1];  // Step 2: Calculate the target sum (skill[i] + skill[j])
        long long totalChemistry = 0;

        int i = 0, j = n - 1;
        while (i < j) {
            int sum = skill[i] + skill[j];
            if (sum != target) return -1;  // Step 3: If any pair doesn't match target sum, return -1

            totalChemistry += 1LL * skill[i] * skill[j];  // Step 4: Add chemistry (product)
            i++;
            j--;
        }

        return totalChemistry;
    }
};
