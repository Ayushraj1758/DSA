class Solution {
public:
    int la(vector<int>& heights) {
        int n=heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())left[i]=0;
            else left[i]=st.top()+1;
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())right[i]=n-1;
            else right[i]=st.top()-1;
            st.push(i);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            int s=(right[i]-left[i]+1)*heights[i];
            maxi=max(maxi,s);
        }
        return maxi;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> height(m,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')height[j]++;
                else
                height[j]=0;
            }
            int area=la(height);
            maxi=max(maxi,area);
            

        }
        return maxi;
        
    }
};