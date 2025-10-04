
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; --i)
            suffix[i] = suffix[i + 1] + piles[i];

        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        function<int(int, int)> solve = [&](int i, int M) -> int {
            if (i >= n) return 0;
            if (2 * M >= n - i) return suffix[i];
            if (dp[i][M]) return dp[i][M];

            int best = 0;
            for (int X = 1; X <= 2 * M; ++X) {
                int next = solve(i + X, max(M, X));
                best = max(best, suffix[i] - next);
            }
            return dp[i][M] = best;
        };

        return solve(0, 1);
    }
};
