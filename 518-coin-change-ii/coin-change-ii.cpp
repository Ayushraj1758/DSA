class Solution {
public:
    int f(int amount,vector<int>&coins,int ind,vector<vector<int>> & dp){
        if(ind==0){
            if(amount % coins[0]==0)return 1;
            return 0; 

        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int nottake=f(amount,coins,ind-1,dp);
        int take=0;
        if(amount>=coins[ind])
            take=f(amount-coins[ind],coins,ind,dp);
        return dp[ind][amount]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp (n,vector<int>(amount+1,-1));
        return f(amount,coins,n-1,dp);
        
    }
};