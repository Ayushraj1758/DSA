class Solution {
public:
    int f(vector<vector<int>>& triangle,vector<vector<int>>& dp,int i,int j ){
        int n=triangle.size();
        if(i==n-1)return triangle[n-1][j];
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        int d=triangle[i][j]+f(triangle,dp,i+1,j);
        int dg=triangle[i][j]+f(triangle,dp,i+1,j+1);
        return dp[i][j]=min(d,dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // int m=triangle.size();;
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        return f(triangle,dp,0,0);
        
        
    }
};