class Solution {
public:
    int f(int ind,int buy,vector<int>& prices,int cap,vector<vector<vector<int>>> & dp){
        int n=prices.size();
        if(cap==0)return 0;
        if(ind==n)return 0;
        if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
        int profit =0;
        if(buy){
            profit=max(-prices[ind]+f(ind+1,0,prices,cap,dp),0+f(ind+1,1,prices,cap,dp));
        }
        else{
            profit=max(prices[ind]+f(ind+1,1,prices,cap-1,dp),0+f(ind+1,0,prices,cap,dp));
        }
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,prices,2,dp);
        
    }
};