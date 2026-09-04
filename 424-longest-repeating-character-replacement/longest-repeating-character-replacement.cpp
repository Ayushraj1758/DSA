class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,r=0,mf=0,mx=0;
        map<char,int>mpp;
        while(r<n){
            mpp[s[r]]++;
            mf=max(mf,mpp[s[r]]);
            // int temp=r-l+1;
            while((r-l+1)-mf > k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0)mpp.erase(s[l]);
                l++;
            }
            mx=max(mx,r-l+1);
            r++;
        }
        return mx;
         
        
    }
};