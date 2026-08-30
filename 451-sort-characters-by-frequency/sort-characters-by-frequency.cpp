class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        map<char,int>mpp;
        for(auto c:s){
            mpp[c]++;

        }
        vector<pair<char,int>> v;
        for(auto it : mpp){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),[](pair<char,int>& a,pair<char,int>&b){
            return a.second>b.second;
        });
        string ans="";
        for(auto it:v){
            ans+=string(it.second,it.first);
        }
        return ans;

    }
};