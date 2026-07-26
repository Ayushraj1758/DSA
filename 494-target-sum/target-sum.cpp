class Solution {
    public:
    int f(vector<int>& nums,int target,int ind,vector<vector<int>>& dp){
        if(ind==0){
            if(target==0 && nums[ind]==0)return 2;
            if(target==0 || nums[ind]==target)return 1;
            return 0;

        }
        if(dp[ind][target]!=-1)return dp[ind][target];
        int nottake=f(nums,target,ind-1,dp);
        int take=0;
        if(target>=nums[ind]){
            take=f(nums,target-nums[ind],ind-1,dp);
        }
        return dp[ind][target]=take+nottake;
    }
    int findTargetSumWays(vector<int>& nums,int target){
        int n=nums.size();
        int ts=0;
        for(int i=0;i<n;i++){
             ts += nums[i];
            // if(s[])
        }
        if(ts-target<0 || (ts-target)%2)return 0;
        vector<vector<int>>dp(n,vector<int>((ts-target)/2+1,-1));
        
        return f(nums,(ts-target)/2,n-1,dp);
        
    }
};