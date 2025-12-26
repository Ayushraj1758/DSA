class Solution {
public:
    int solve(vector<int>& slices, int l, int r, int n) {
        vector<int> prev(n + 1, 0), prev2(n + 1, 0), cur(n + 1, 0);

        for (int i = l; i <= r; i++) {
            for (int j = 1; j <= n; j++) {
                cur[j] = max(
                    prev[j],               // skip current slice
                    prev2[j - 1] + slices[i]  // take current slice
                );
            }
            prev2 = prev;
            prev = cur;
        }
        return prev[n];
    }

    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size() / 3;

        // Case 1: exclude last slice
        int case1 = solve(slices, 0, slices.size() - 2, n);

        // Case 2: exclude first slice
        int case2 = solve(slices, 1, slices.size() - 1, n);

        return max(case1, case2);
    }
};
