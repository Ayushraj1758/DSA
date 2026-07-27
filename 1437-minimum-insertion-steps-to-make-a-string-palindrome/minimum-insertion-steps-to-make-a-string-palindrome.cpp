class Solution {
public:
    int f(string &s1,string & s2,int i1,int i2,vector<vector<int>> &dp){
        if(i1<0 || i2<0)return 0;
        if(dp[i1][i2]!=-1)return dp[i1][i2];

        if(s1[i1]==s2[i2])return dp[i1][i2]=1+f(s1,s2,i1-1,i2-1,dp);
        else 
        return dp[i1][i2]=0+max(f(s1,s2,i1-1,i2,dp),f(s1,s2,i1,i2-1,dp));        
        
    }
    int minInsertions(string s) {
        int n=s.size();
        string s1;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(char c:s)s1=c+s1;
        return n- f(s,s1,n-1,n-1,dp);
        
    }
};