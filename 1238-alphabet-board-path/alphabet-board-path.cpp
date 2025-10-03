#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string alphabetBoardPath(string target) {
        string ans;
        int curRow = 0, curCol = 0;

        for (char c : target) {
            int idx = c - 'a';
            int row = idx / 5;
            int col = idx % 5;

            // Special handling to avoid invalid moves for 'z'
            if (c == 'z') {
                // move horizontally first
                while (curCol > col) { ans.push_back('L'); curCol--; }
                while (curCol < col) { ans.push_back('R'); curCol++; }
                while (curRow < row) { ans.push_back('D'); curRow++; }
                while (curRow > row) { ans.push_back('U'); curRow--; }
            } else {
                // move vertically first when leaving 'z'
                while (curRow > row) { ans.push_back('U'); curRow--; }
                while (curCol > col) { ans.push_back('L'); curCol--; }
                while (curCol < col) { ans.push_back('R'); curCol++; }
                while (curRow < row) { ans.push_back('D'); curRow++; }
            }

            ans.push_back('!');
        }
        return ans;
    }
};