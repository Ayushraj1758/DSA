class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // key: (i - j), value: all elements on that diagonal
        unordered_map<int, vector<int>> diag;

        // Collect elements for each diagonal
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                diag[i - j].push_back(mat[i][j]);
            }
        }

        // Sort each diagonal in descending order
        // so we can pop_back() to place them in ascending order
        for (auto &p : diag) {
            auto &v = p.second;
            sort(v.begin(), v.end(), greater<int>());
        }

        // Put back sorted elements (ascending along each diagonal)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int key = i - j;
                mat[i][j] = diag[key].back();
                diag[key].pop_back();
            }
        }

        return mat;
    }
};
