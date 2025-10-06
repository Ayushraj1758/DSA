class Solution {
public:
    
int maxRepOpt1(string text) {
    unordered_map<char, int> count; // total count of each character
    for (char c : text) {
        count[c]++;
    }

    int maxLen = 0;
    int n = text.size();

    for (int i = 0; i < n;) {
        char currentChar = text[i];
        int j = i;

        // Count length of current repeated block
        while (j < n && text[j] == currentChar) j++;
        int len1 = j - i;

        // Try to merge separated blocks like: aaa_b_aaa
        int k = j + 1;
        while (k < n && text[k] == currentChar) k++;
        int len2 = (j < n && text[j] != currentChar) ? k - j - 1 : 0;

        int total = len1 + len2;

        // If we have more occurrences of the character elsewhere, we can extend by 1
        if (count[currentChar] > total) total++;

        maxLen = max(maxLen, total);

        // Move to next block
        i = j;
    }

    return maxLen;
}

};


int maxRepOpt1(string text) {
    unordered_map<char, int> count; // total count of each character
    for (char c : text) {
        count[c]++;
    }

    int maxLen = 0;
    int n = text.size();

    for (int i = 0; i < n;) {
        char currentChar = text[i];
        int j = i;

        // Count length of current repeated block
        while (j < n && text[j] == currentChar) j++;
        int len1 = j - i;

        // Try to merge separated blocks like: aaa_b_aaa
        int k = j + 1;
        while (k < n && text[k] == currentChar) k++;
        int len2 = (j < n && text[j] != currentChar) ? k - j - 1 : 0;

        int total = len1 + len2;

        // If we have more occurrences of the character elsewhere, we can extend by 1
        if (count[currentChar] > total) total++;

        maxLen = max(maxLen, total);

        // Move to next block
        i = j;
    }

    return maxLen;
}
