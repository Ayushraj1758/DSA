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

//for space optimization dp[i]=cur,dp[i-1]=prev
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1,0));
        vector<int>cur(amount+1,0),prev(amount+1,0);

        for(int i=0;i<=amount;i++){
            if(i % coins[0]==0)prev[i] =i / coins[0];//dp[0][i]=i/coins[0];
            else
            prev[i]=1e9;//dp[0][i]=1e9;

        }
        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                int nottake=0+prev[t];
                int take=1e9;
                if(coins[i]<=t)
                take=1+cur[t-coins[i]];
                cur[t]=min(take,nottake);
            }
            prev=cur;
        }
        int ans=prev[amount];
        if(ans>=1e9)return -1;
        else return ans;

    }
};