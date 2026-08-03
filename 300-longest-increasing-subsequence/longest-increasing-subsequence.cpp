class Solution {
public:
    int f(vector<int> & nums,int ind,int pi,vector<vector<int>> & dp){
        int n=nums.size();
        if(ind==n)return 0;
        if(dp[ind][pi+1]!=-1)return dp[ind][pi+1];
        int nottake=0+f(nums,ind+1,pi,dp);
        int take=0,maxi=INT_MIN;
        if(pi==-1 || nums[ind]>nums[pi])
        take=1+f(nums,ind+1,ind,dp);
        maxi=max(take,nottake);
        return dp[ind][pi+1]=maxi;
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(nums,0,-1,dp);
        
    }
};