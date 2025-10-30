
class Solution {
public:
    int maxLen = 0;

    void backtrack(vector<int>& masks, int idx, int currMask, int currLen) {
        maxLen = max(maxLen, currLen);
        for (int i = idx; i < masks.size(); i++) {
            if ((currMask & masks[i]) == 0) {  // no overlap
                backtrack(masks, i + 1, currMask | masks[i], currLen + __builtin_popcount(masks[i]));
            }
        }
    }

    int maxLength(vector<string>& arr) {
        vector<int> masks;
        for (string& s : arr) {
            int mask = 0;
            bool valid = true;
            for (char c : s) {
                int bit = c - 'a';
                if (mask & (1 << bit)) { // duplicate character in string
                    valid = false;
                    break;
                }
                mask |= (1 << bit);
            }
            if (valid) masks.push_back(mask);
        }
        backtrack(masks, 0, 0, 0);
        return maxLen;
    }
};
