class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        stack<int> st;
        st.push(INT_MAX); // Sentinel value

        for (int x : arr) {
            while (st.top() <= x) {
                int mid = st.top();
                st.pop();
                res += mid * min(st.top(), x);
            }
            st.push(x);
        }

        // Process remaining stack
        while (st.size() > 2) {
            int mid = st.top();
            st.pop();
            res += mid * st.top();
        }

        return res;
    }
};
