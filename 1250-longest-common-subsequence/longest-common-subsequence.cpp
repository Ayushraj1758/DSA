class Solution {
public:
    int f(string &t1,string &t2,int ind1,int ind2,vector<vector<int>> &dp){
        if(ind1<0  || ind2 < 0)return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];

        if(t1[ind1]==t2[ind2])return dp[ind1][ind2]=1+f(t1,t2,ind1-1,ind2-1,dp);
        return dp[ind1][ind2]=0+max(f(t1,t2,ind1-1,ind2,dp),f(t1,t2,ind1,ind2-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return f(text1,text2,n1-1,n2-1,dp);

       
    }
};