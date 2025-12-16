class Solution {
public:
    int maximum69Number (int num) {
        // int rev=0;
        // for(int i=num;i>0;i/=10){
        //     int x=i%10;
        //     rev=rev*10+x;
        // }
        // for(int i=rev;i>0;i/=10){
        //     int x=i%10;
        //     if(x==6)
        //     y=9;
        //     else
        //     y=x;

        //     number=number*10+y;

        // }
        string s=to_string(num);
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='6'){
                s[i]='9';
                break;
            }
        }
        int x=stoi(s);
        return x;
        
    }
};