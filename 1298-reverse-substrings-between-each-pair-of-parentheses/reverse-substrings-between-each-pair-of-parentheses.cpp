class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr = "";

        for (char c : s) {
            if (c == '(') {
                // Push current substring and reset
                st.push(curr);
                curr = "";
            } else if (c == ')') {
                // Reverse the current substring
                reverse(curr.begin(), curr.end());
                // Append to previous substring
                curr = st.top() + curr;
                st.pop();
            } else {
                curr += c;
            }
        }
        return curr;
    }
};
