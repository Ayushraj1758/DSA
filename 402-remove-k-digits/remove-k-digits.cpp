class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        int n=num.size();
        for(char x:num){
         
            while(!st.empty() && k>0 && st.back()>x){
                st.pop_back();k--;
            }
        
            st.push_back(x);
        }
        while(k>0){
            st.pop_back();
            k--;

        }
      
        int i=0;
        while(i<st.size() && st[i]=='0'){
            i++;
        }
        st=st.substr(i);
        return st.empty()?"0":st;
    }
};