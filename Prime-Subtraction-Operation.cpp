class Solution {
public:
    

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        const int MAX = 1000; // All nums[i] <= 1000
        vector<int> primes = getPrimes(MAX);

        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) continue;
            // Try subtracting largest prime < nums[i] to make it < nums[i+1]
            bool found = false;
            for (int j = 0; j < primes.size(); ++j) {
                int p = primes[j];
                if (p >= nums[i]) break;
                if (nums[i] - p < nums[i + 1]) {
                    nums[i] -= p;
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }

private:
    vector<int> getPrimes(int max) {
        vector<bool> isPrime(max + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= max; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= max; j += i)
                    isPrime[j] = false;
            }
        }
        vector<int> primes;
        for (int i = 2; i <= max; ++i) {
            if (isPrime[i]) primes.push_back(i);
        }
        return primes;
    }
};
