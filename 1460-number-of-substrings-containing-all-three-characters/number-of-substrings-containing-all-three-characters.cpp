class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        map<char,int>mpp;
        int cnt=0;
        // for(int i=0;i<n;i++){
        //     mpp.clear();
        //     for(int j=i;j<n;j++){
        //         mpp[s[j]]++;
        //         if(mpp.size()==3)cnt++;
        //     }
        // }
        // return cnt;
        
        //two pointer

        int l=n-1,r=n-1;
        while(r>=0){
            mpp[s[r]]++;
            
            while(mpp.size()==3){
                cnt+=r+1;
                mpp[s[l]]--;
                if(mpp[s[l]]==0)mpp.erase(s[l]);
                l--;
                
            }
            
            r--;
        }
        return cnt;
    }
};