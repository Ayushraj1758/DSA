class Solution {
public:
    // int f(int ind,int jumps,int n,vector<int> & nums,vector<vector<int>> &dp){
    //     if(ind>=n-1)return jumps;
    //     if(dp[ind][jumps]!=-1)return dp[ind][jumps];
    //     int mini=INT_MAX;
    //     for(int i=0;i<n;i++){
    //         mini=min(mini,f(ind+i,jumps+1,n,nums,dp));
    //     }
    //     return dp[ind][jumps]=mini;


    // }
    int jump(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>> dp(n,vector<int> (n,-1));
        int jumps=0,l=0,r=0;
        while(r<n-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(i+nums[i],farthest);
            }
            l=r+1;
            r=farthest;
            jumps++;

        }
        return jumps;

        
    }
};