// class Solution {
// public:
//     bool f(string &s,string &p,int i,int j,vector<vector<int>>& dp){
//         if(i<0 && j<0)return true;
//         if(i<0){
//             for(int k=0;k<=j;k++){
//                 if(p[k]!='*')return false;
//             }
//         return true;
//         }
        
//         if(j<0)return false;

//         if(dp[i][j]!=-1)return dp[i][j];
//         if(s[i]==p[j] || p[j]=='?')return dp[i][j]=f(s,p,i-1,j-1,dp);
//         if(p[j]=='*')return dp[i][j]=(f(s,p,i-1,j,dp) || f(s,p,i,j-1,dp));
//         return dp[i][j]=false;

//     }
//     bool isMatch(string s, string p) {
//         int n=s.size();
//         int m=p.size();
//         vector<vector<int>> dp(n,vector<int>(m,-1));
//         return f( s, p,n-1,m-1,dp);
        
//     }
// };


//+1 indexing 
// class Solution {
// public:
//     bool f(string &s,string &p,int i,int j,vector<vector<int>>& dp){
//         if(i==0 && j==0)return true;
//         if(i==0 && j>0){
//             for(int k=1;k<=j;k++){
//                 if(p[k-1]!='*')return false;
//             }
//         return true;
//         }
        
//         if(j==0 && i>0)return false;

//         if(dp[i][j]!=-1)return dp[i][j];
        // if(s[i-1]==p[j-1] || p[j-1]=='?')return dp[i][j]=f(s,p,i-1,j-1,dp);
        // if(p[j-1]=='*')return dp[i][j]=(f(s,p,i-1,j,dp) || f(s,p,i,j-1,dp));
        // return dp[i][j]=false;

//     }
//     bool isMatch(string s, string p) {
//         int n=s.size();
//         int m=p.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//         return f( s, p,n,m,dp);
        
//     }
// };

//tabulation
class Solution {
    public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        // vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));   
        vector<bool> prev(n+1,false),cur(m+1,false);
        prev[0]=true;
        for(int j=1;j<=m;j++){
            bool flag=true;
            for(int k=1;k<=j;k++){
                if(p[k-1]!='*'){
                    flag=false;break;
                } 
            } 
            prev[j]=flag;
     }
     for(int i=1;i<=n;i++){
        cur[0]=false;
     }
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // cur[0]=false;
            if(s[i-1]==p[j-1] || p[j-1]=='?')cur[j]=prev[j-1];
            else if(p[j-1]=='*') cur[j]=prev[j] || cur[j-1];
            else  cur[j]=false;

        }
        prev=cur;
     }
     return prev[m];

    }

};