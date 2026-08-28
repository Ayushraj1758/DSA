class Solution {
public:
    // bool f(int ind,string &s,int cnt,vector<vector<int>> &dp){
    //     int n=s.size();
    //     if(cnt<0)return false;
    //     if(ind==n)return (cnt==0);
    //     if(dp[ind][cnt]!=-1)return dp[ind][cnt];
    //     if(s[ind]=='(')return dp[ind][cnt]=f(ind+1,s,cnt+1,dp);
    //     if(s[ind]==')')return dp[ind][cnt]=f(ind+1,s,cnt-1,dp);
    //     else{
    //         return dp[ind][cnt]=(f(ind+1,s,cnt-1,dp) || f(ind+1,s,cnt+1,dp) || f(ind+1,s,cnt,dp));
    //     }
    // }
//     bool checkValidString(string s) {
//         int n=s.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         return f(0,s,0,dp);
        
//     }
// };

//tc=O(n)
bool checkValidString(string s) {
        int n=s.size();
        int min=0,max=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                min=min+1;
                max=max+1;
            }
            else if(s[i]==')'){
                min=min-1;max=max-1;
            }
            else{
                min=min-1;max=max+1;
            }
            if(min<0)min=0;
            if(max<0)return false;

        }
        return (min==0);
        
    }
};