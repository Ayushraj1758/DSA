class Solution {
public:
    int f(string s) {
        char smallest = 'z';
        int freq = 0;
        for (char c : s) {
            if (c < smallest) {
                smallest = c;
                freq = 1;
            } else if (c == smallest) {
                freq++;
            }
        }
        return freq;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> wordFreq;
        for (auto &w : words)
            wordFreq.push_back(f(w));

        sort(wordFreq.begin(), wordFreq.end());  // For binary search

        vector<int> result;
        for (auto &q : queries) {
            int fq = f(q);
            // Count how many word frequencies are > fq
            int count = wordFreq.end() - upper_bound(wordFreq.begin(), wordFreq.end(), fq);
            result.push_back(count);
        }

        return result;
    }
};
