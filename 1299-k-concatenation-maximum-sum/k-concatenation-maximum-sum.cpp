
class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long kadane(const vector<int>& arr) {
        long long maxSum = 0, curr = 0;
        for (int x : arr) {
            curr = max(0LL, curr + x);
            maxSum = max(maxSum, curr);
        }
        return maxSum;
    }

    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long totalSum = accumulate(arr.begin(), arr.end(), 0LL);

        // Case 1: k == 1 → just Kadane on single array
        if (k == 1)
            return kadane(arr) % MOD;

        // Case 2: Kadane on double array (to capture wrap-around)
        vector<int> twice;
        twice.reserve(arr.size() * 2);
        twice.insert(twice.end(), arr.begin(), arr.end());
        twice.insert(twice.end(), arr.begin(), arr.end());

        long long maxDouble = kadane(twice);

        long long result;
        if (totalSum > 0)
            result = maxDouble + (k - 2) * totalSum;
        else
            result = maxDouble;

        result %= MOD;
        return (int)((result + MOD) % MOD);
    }
};
