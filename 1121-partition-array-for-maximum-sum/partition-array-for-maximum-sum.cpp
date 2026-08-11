class Solution {
public:
    int f(int ind,vector<int>& arr,int k,int n,vector<vector<int>>&dp){
        if(ind==n)return 0;
        if(dp[ind][k]!=-1)return dp[ind][k];
        int me=INT_MIN,mans=INT_MIN;
        for(int len=0,j=ind;j<min(n,ind+k);j++){
            len++;
            me=max(me,arr[j]);
            int sum=len*me+f(j+1,arr,k,n,dp);
            mans=max(mans,sum);
        }
        return dp[ind][k]=mans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return f(0,arr,k,n,dp);
        
    }
};