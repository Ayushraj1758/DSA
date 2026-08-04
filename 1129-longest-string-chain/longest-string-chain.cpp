class Solution {
public:

    bool checks(string &s1,string &s2){
        int n=s1.size();
        int m=s2.size();
        if(n!=m+1)return false;
        int f=0,s=0;
        while(f<n){
            if(s<m && s1[f]==s2[s]){f++;s++;}
            else{
                f++;
            }

        }
        if(f==n && s==m)return true;
        return false;
    }

    static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),comp);//used for sorting the string lengthwise
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j< i;j++){
                if(checks(words[i],words[j]) && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
            maxi=max(maxi,dp[i]);

        }
        return maxi;
        
    }
};