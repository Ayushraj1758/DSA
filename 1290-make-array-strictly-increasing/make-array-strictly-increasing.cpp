class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        map<int, int> dp;
        dp[-1] = 0; // base case

        for (int a : arr1) {
            map<int, int> new_dp;

            for (auto [prev, cost] : dp) {
                // Option 1: keep a (if it's greater than previous)
                if (a > prev) {
                    if (new_dp.count(a))
                        new_dp[a] = min(new_dp[a], cost);
                    else
                        new_dp[a] = cost;
                }

                // Option 2: replace a with next greater element from arr2
                auto it = upper_bound(arr2.begin(), arr2.end(), prev);
                if (it != arr2.end()) {
                    int new_val = *it;
                    if (new_dp.count(new_val))
                        new_dp[new_val] = min(new_dp[new_val], cost + 1);
                    else
                        new_dp[new_val] = cost + 1;
                }
            }

            dp = move(new_dp);
            if (dp.empty()) return -1;
        }

        int ans = INT_MAX;
        for (auto [_, cost] : dp)
            ans = min(ans, cost);
        return ans;
    }
};
