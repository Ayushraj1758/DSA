class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> freq;
        for (auto &d : dominoes) {
            int a = d[0], b = d[1];
            int key = min(a, b) * 10 + max(a, b);
            freq[key]++;
        }

        int res = 0;
        for (auto &p : freq) {
            int cnt = p.second;
            res += cnt * (cnt - 1) / 2;
        }
        return res;
    }
};
