class Solution {
public:
    int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>> & dp,int n){
        
        if(j<0 || j>=n)return 1e8;
        if(i==0){
            return matrix[i][j];
        }
        if(dp[i][j]!=INT_MAX)return dp[i][j];

        int left=matrix[i][j]+f(i-1,j-1,matrix,dp,n);
        int right=matrix[i][j]+f(i-1,j+1,matrix,dp,n);
        int up=matrix[i][j]+f(i-1,j,matrix,dp,n);
        return dp[i][j]=min(left,min(right,up));


    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp (n,vector<int>(n,INT_MAX));
        int ans=INT_MAX;    
        for(int i=0;i<n;i++){
            ans=min(ans,f(n-1,i,matrix,dp,n));
        }
        return ans;
        
    }
};