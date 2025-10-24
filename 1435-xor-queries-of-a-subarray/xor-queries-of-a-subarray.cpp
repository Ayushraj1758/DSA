
class Solution {
public:
    // arr: input array
    // queries: vector of [L, R]
    // returns vector where each element is XOR of arr[L..R]
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        // prefix[i] = XOR of arr[0..i-1], prefix[0] = 0
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] ^ arr[i - 1];
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto &q : queries) {
            int L = q[0], R = q[1];
            // XOR of arr[L..R] = prefix[R+1] ^ prefix[L]
            ans.push_back(prefix[R + 1] ^ prefix[L]);
        }
        return ans;
    }
};
