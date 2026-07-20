class Solution {
public:
    bool f(vector<int>&nums,int i,int s,vector<vector<int>>& dp){
        if(s==0)return true;
        if(i==0)return (nums[0]==s);
        if(dp[i][s]!=-1)return dp[i][s];
        bool nottake=f(nums,i-1,s,dp);
        bool take=false;
        if(s>=nums[i]){
        take=f(nums,i-1,s-nums[i],dp);
        }
        return dp[i][s]=(take || nottake);

    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int s=sum/2;
        vector<vector<int>>dp(n,vector<int>(s+1,-1));        
        if(sum%2!=0)return false;

        else{
            return f(nums, n-1,s,dp);
        }
        
    }
};