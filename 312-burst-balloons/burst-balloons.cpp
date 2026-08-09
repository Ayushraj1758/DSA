class Solution {
public:
int f(int i,int j,vector<int>& nums,vector<vector<int>> & dp){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int mx=INT_MIN;
    for(int ind=i;ind<=j;ind++){
        int cost=nums[i-1]*nums[ind]*nums[j+1]+f(i,ind-1,nums,dp)+f(ind+1,j,nums,dp);
        mx=max(mx,cost);
    }
    return dp[i][j]=mx;
}
    int maxCoins(vector<int>& nums) {

        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int m=nums.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return f(1,m-2,nums,dp);

        
    }
};