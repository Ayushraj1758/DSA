class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        
        string ans="";
        int si=-1;
        int mini=1e9;
        int m=t.size();
            map<char,int>mpp;
        // for(int i=0;i<n;i++){
        //     mpp.clear();
        //     for(auto x:t)mpp[x]++;
        //     int cnt=0;
        //     for(int j=i;j<n;j++){
        //         if(mpp[s[j]]>0)cnt++;
        //         mpp[s[j]]--;
        //         if(cnt==m){
        //             if(j-i+1<mini){
        //             mini=j-i+1;
        //             // mini=min(mini,j-i+1);
        //             si=i;
        //             }
        //             break;
        //         }
        //     }
        // }
        // if(si==-1)return "";
        // for(int k=si;k<(mini+si);k++){
        //     ans+=s[k];
        // }
        // // return ans;
        // // return s.substr(si,mini);
        // return ans;

        //two pointer
        int l=0,r=0,cnt=0;

        for(auto x:t)mpp[x]++;
        while(r<n){

            if(mpp[s[r]]>0)cnt++;
            mpp[s[r]]--;
            while(cnt==m){
                if(r-l+1<mini){
                    mini=r-l+1;
                    si=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0)cnt--;
                l++;
            }

            r++;
        }
        if(si==-1)return "";
        return s.substr(si,mini);
    }
};