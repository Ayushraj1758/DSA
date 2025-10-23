class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<long long> prefix(n+1, 0); // prefix[i] = sum of arr[0..i-1]
        for (int i = 0; i < n; ++i) prefix[i+1] = prefix[i] + arr[i];

        // If total sum already <= target, return max element (no mutation helps)
        if (prefix[n] <= target) return arr.back();

        int bestVal = 0;
        int bestDiff = INT_MAX;

        // iterate through breakpoints
        for (int i = 0; i < n; ++i) {
            long long sumBefore = prefix[i];        // sum of elements < arr[i]
            int remaining = n - i;                 // number of elements that would be replaced by cap

            // If capping all remaining elements at arr[i] already reaches or exceeds target
            long long totalIfCapAtAi = sumBefore + 1LL * arr[i] * remaining;
            if (totalIfCapAtAi >= target) {
                // Ideal cap (floor). Check both floor and floor+1
                long long raw = (target - sumBefore) / remaining; // floor division
                for (long long cand = max(0LL, raw - 1); cand <= raw + 1; ++cand) {
                    long long total = sumBefore + cand * remaining;
                    int diff = (int) llabs(total - target);
                    if (diff < bestDiff || (diff == bestDiff && (int)cand < bestVal)) {
                        bestDiff = diff;
                        bestVal = (int)cand;
                    }
                }
                return bestVal; // once we find a breakpoint where we can reach target, we're done
            }
            // else, even capping at arr[i] gives sum < target, continue
        }

        // If we finished loop without returning, we must select the largest array value
        // (but we handled prefix[n] <= target earlier). Still, to be safe:
        // compute diff for arr.back()
        long long total = prefix[n];
        int diff = (int) llabs(total - target);
        if (diff < bestDiff || (diff == bestDiff && arr.back() < bestVal)) bestVal = arr.back();
        return bestVal;
    }
};
