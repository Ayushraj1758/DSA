class Solution {
public:

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    int n=strs.size();
    
    // string prefix = strs[0];
    
    // for (int i = 1; i < strs.size(); ++i) {
    //     while (strs[i].find(prefix) != 0) {
    //         prefix = prefix.substr(0, prefix.size() - 1);
    //         if (prefix.empty()) return "";
    //     }
    // }
    // return prefix;
    string st=strs[0],ans="";
    for(int i=0;i<strs[0].size();i++){
        // char x=st[i];
        bool temp=true;
        for(int j=1;j<n;j++){
            if(st[i]!=strs[j][i]){
                temp=false;break;
            }
        }
        if(!temp)break;
        else{
            ans+=st[i];
        }
        
    }
    return ans;

}
        
    
};