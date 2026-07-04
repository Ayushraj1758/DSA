class Solution {
public:
    int f(vector<int> &nums,vector<int> &dp,int ind){
        if(ind==0)return nums[ind];
        if(ind==-1)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int pick=nums[ind]+f(nums,dp,ind-2);
        
        int notpick=0+f(nums,dp,ind-1);
        return dp[ind]=max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        int ind=nums.size();
        vector<int> dp(ind,-1);
        return f(nums,dp,ind-1);
        
    }
};