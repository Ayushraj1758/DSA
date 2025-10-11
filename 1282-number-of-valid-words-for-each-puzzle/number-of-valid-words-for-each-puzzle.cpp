
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> freq;
        
        // Step 1: Convert words to bitmask and count frequency
        for (auto& w : words) {
            int mask = 0;
            for (char c : w)
                mask |= 1 << (c - 'a');
            // Skip words with more than 7 unique letters (no puzzle can match them)
            if (__builtin_popcount(mask) <= 7)
                freq[mask]++;
        }

        vector<int> ans;
        
        // Step 2: Process each puzzle
        for (auto& p : puzzles) {
            int mask = 0;
            for (char c : p)
                mask |= 1 << (c - 'a');
            
            int first = 1 << (p[0] - 'a');
            int submask = mask;
            int count = 0;
            
            // Step 3: Iterate over all submasks
            for (int sub = mask; sub; sub = (sub - 1) & mask) {
                if (sub & first)
                    count += freq[sub];
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};
