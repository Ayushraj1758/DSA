class Solution {
public:
    int palin(int i,int j,string &str){
        while(i<j){
            if(str[i]!=str[j])return 0;
            else{
                i++;j--;
            }
        }return 1;
    }
    int f(string &s ,int i,int n,vector<int>&dp){
        
        if(i==n)return 0;
        int mini=INT_MAX;
        if(dp[i]!=-1)return dp[i];
        for(int j=i;j<n;j++){
           
            if(palin(i,j,s)){

            int cost=1+f(s,j+1,n,dp);
            mini=min(mini,cost);
            }
        }
        return dp[i]=mini;

    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return f(s,0,n,dp)-1;
        
    }
};