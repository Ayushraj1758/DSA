class Solution {
public:
    int MOD = 1e9 + 7;

    int numOfArrays(int n, int m, int k) {
        static int dp[51][51][101];
        memset(dp, 0, sizeof(dp));

        // Base case
        for (int i = 1; i <= m; i++) {
            dp[1][1][i] = 1;
        }

        for (int len = 1; len < n; len++) {
            for (int cost = 1; cost <= k; cost++) {
                for (int mx = 1; mx <= m; mx++) {
                    if (dp[len][cost][mx] == 0) continue;

                    // Case 1: add value <= mx
                    long long sameMax = (long long)dp[len][cost][mx] * mx;
                    dp[len + 1][cost][mx] = 
                        (dp[len + 1][cost][mx] + sameMax) % MOD;

                    // Case 2: add value > mx
                    for (int newMx = mx + 1; newMx <= m; newMx++) {
                        dp[len + 1][cost + 1][newMx] =
                            (dp[len + 1][cost + 1][newMx] + dp[len][cost][mx]) % MOD;
                    }
                }
            }
        }

        int ans = 0;
        for (int mx = 1; mx <= m; mx++) {
            ans = (ans + dp[n][k][mx]) % MOD;
        }

        return ans;
    }
};
