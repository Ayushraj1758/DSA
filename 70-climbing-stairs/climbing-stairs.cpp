class Solution {
public:
    int climbStairs(int n) {
        if(n<3)return n;
        int a=1,b=2;
        for(int i=3;i<=n;i++){
        int c=a+b;
        a=b;
        b=c;
        }
        return b;
        
    }
    // int f(int ind){
    //     if(ind==0 || ind==1 || ind==2)return ind;
    //     // int left=f(ind-1);
    //     // int right = f(ind-2);
    //     return f(ind-1)+f(ind-2);
    // }
    // int climbStairs(int n){
    //     return f(n);

    // }
};