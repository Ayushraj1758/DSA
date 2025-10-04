class Solution {
public:
    
int largest1BorderedSquare(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> left(m, vector<int>(n, 0));
    vector<vector<int>> up(m, vector<int>(n, 0));
    int ans = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                left[i][j] = (j > 0 ? left[i][j - 1] : 0) + 1;
                up[i][j] = (i > 0 ? up[i - 1][j] : 0) + 1;

                int small = min(left[i][j], up[i][j]);
                while (small > 0) {
                    if (up[i][j - small + 1] >= small && left[i - small + 1][j] >= small) {
                        ans = max(ans, small * small);
                        break;
                    }
                    small--;
                }
            }
        }
    }
    return ans;
}
};