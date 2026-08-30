class Solution {
public:
    bool isPowerOfTwo(int n) {
        string s;
        for(int i=n;i>0;i/=2){
            if(i%2==0)s+='0';
            else
            s+='1';
        }
        // reverse(s.begin().s.end());
        int x=s.size();
        int cnt=0;
        for(int i=0;i<x;i++){
            if(s[i]=='1')cnt++;

        }

        if(cnt==1)return true;
        else
        return false;
    }
};