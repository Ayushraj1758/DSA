class Solution {
public:
    int f(string &t1,string &  t2,int ind1,int ind2,vector<vector<int>> &dp){
        if(ind1<0  || ind2 < 0)return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];

        if(t1[ind1]==t2[ind2])return dp[ind1][ind2]=1+f(t1,t2,ind1-1,ind2-1,dp);
        return dp[ind1][ind2]=0+max(f(t1,t2,ind1-1,ind2,dp),f(t1,t2,ind1,ind2-1,dp));
    }
    int longestPalindromeSubseq(string s) {
        
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        string s1;
        for(auto c:s)s1=c+s1;
        return f(s,s1,n-1,n-1,dp);
    }
};