
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int n = mat.size();
        if (n == 0) return {};
        int m = mat[0].size();

        // Prefix sum matrix P with size (n+1) x (m+1)
        vector<vector<int>> P(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            int rowSum = 0;
            for (int j = 0; j < m; ++j) {
                rowSum += mat[i][j];
                P[i + 1][j + 1] = P[i][j + 1] + rowSum; // or P[i+1][j] + P[i][j+1] - P[i][j] + mat[i][j]
            }
        }

        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // block corners clipped to matrix bounds
                int r1 = max(0, i - K);
                int c1 = max(0, j - K);
                int r2 = min(n - 1, i + K);
                int c2 = min(m - 1, j + K);

                // convert to prefix indices (1-based in P)
                int R1 = r1, C1 = c1, R2 = r2, C2 = c2;
                // sum over rectangle [R1..R2][C1..C2]
                int sum = P[R2 + 1][C2 + 1] - P[R1][C2 + 1] - P[R2 + 1][C1] + P[R1][C1];
                ans[i][j] = sum;
            }
        }
        return ans;
    }
};
