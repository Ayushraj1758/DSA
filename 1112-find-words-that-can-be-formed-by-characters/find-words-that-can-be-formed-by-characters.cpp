
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26, 0);
        for (char c : chars) freq[c - 'a']++;

        int totalLength = 0;

        for (auto& word : words) {
            vector<int> temp = freq;
            bool canForm = true;

            for (char c : word) {
                if (--temp[c - 'a'] < 0) {
                    canForm = false;
                    break;
                }
            }

            if (canForm) totalLength += word.size();
        }

        return totalLength;
    }
};