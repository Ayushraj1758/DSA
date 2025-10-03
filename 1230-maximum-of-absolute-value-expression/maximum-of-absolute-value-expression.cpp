#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int ans = 0;

        vector<int> s1 = {1, 1, -1, -1};
        vector<int> s2 = {1, -1, 1, -1};

        for (int k = 0; k < 4; k++) {
            int mx = INT_MIN, mn = INT_MAX;
            for (int i = 0; i < n; i++) {
                int val = s1[k] * arr1[i] + s2[k] * arr2[i] + i;
                mx = max(mx, val);
                mn = min(mn, val);
            }
            ans = max(ans, mx - mn);
        }

        return ans;
    }
};
