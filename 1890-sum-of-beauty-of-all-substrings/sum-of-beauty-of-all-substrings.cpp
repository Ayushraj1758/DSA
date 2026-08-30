class Solution {
public:
// int f(string s){
//     int n=s.size();
//         map<char,int>mpp;
//         for(int i=0;i<n;i++){
//             mpp[s[i]]++;
//         }
//         vector<pair<char,int>>v;
//         for(auto it:mpp){
//             v.push_back({it.first,it.second});
//         }
//         sort(v.begin(),v.end(),[](pair<char,int>&a,pair<char,int>& b){
//             return a.second>b.second;
//         });
        
//         int diff=v[0].second-v[v.size()-1].second;
//         return diff;
// }
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
        vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j] -'a']++;

                int maxi=0;
                int mini=INT_MAX;
                for(int k=0;k<26;k++){
                    if(freq[k]>0){

                    maxi=max(maxi,freq[k]);
                    mini=min(mini,freq[k]);
                    }
                }
            ans+=(maxi-mini);
            }
        }
        return ans;
        
    }
};