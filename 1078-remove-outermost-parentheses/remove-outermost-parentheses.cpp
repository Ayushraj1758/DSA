class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        int n=s.size();
        string ans="";
        for(auto c:s){
            if(c=='('){
                if(cnt>0)
                ans+=c;
            cnt++;
            }
            else{
                cnt--;
                if(cnt>0)
                ans+=c;
            }
        }
        return ans;
        
    }
};