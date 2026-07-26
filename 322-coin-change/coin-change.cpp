// class Solution {
// public:
//     int f(vector<int> & coins,int amount,int ind,vector<vector<int>>& dp){
//         if(ind==0){
//             if(amount % coins[ind]==0)return amount / coins[ind];
//             else return 1e9;

//         }
//         if(dp[ind][amount]!=-1)return dp[ind][amount];
        
//         int nottake=0+f(coins,amount,ind-1,dp);
//         int take=1e9;
//         if(coins[ind]<=amount){
//             take=1+f(coins,amount-coins[ind],ind,dp);
//         }
//         return dp[ind][amount]=min(take,nottake);
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int n=coins.size();
//         vector<vector<int>> dp(n,vector<int>(amount+1,-1));
//         int ans=f(coins,amount,n-1,dp);
//         if(ans>=1e9)return -1;
//         else
//         return ans;

        
//     }
// };

//tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i % coins[0]==0)dp[0][i]=i / coins[0];
            else
            dp[0][i]=1e9;

        }
        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                int nottake=0+dp[i-1][t];
                int take=1e9;
                if(coins[i]<=t)
                take=1+dp[i][t-coins[i]];
                dp[i][t]=min(take,nottake);
            }
        }
        int ans=dp[n-1][amount];
        if(ans>=1e9)return -1;
        else return ans;

    }
};