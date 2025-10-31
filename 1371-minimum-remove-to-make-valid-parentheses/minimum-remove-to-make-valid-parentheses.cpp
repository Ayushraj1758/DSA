
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        string temp;
        int balance = 0;

        // First pass: remove invalid ')'
        for (char c : s) {
            if (c == '(') {
                balance++;
                temp.push_back(c);
            } else if (c == ')') {
                if (balance > 0) {
                    balance--;
                    temp.push_back(c);
                }
            } else {
                temp.push_back(c);
            }
        }

        // Second pass: remove extra '(' from right to left
        string result;
        balance = 0;
        for (int i = temp.size() - 1; i >= 0; i--) {
            char c = temp[i];
            if (c == ')') {
                balance++;
                result.push_back(c);
            } else if (c == '(') {
                if (balance > 0) {
                    balance--;
                    result.push_back(c);
                }
            } else {
                result.push_back(c);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
