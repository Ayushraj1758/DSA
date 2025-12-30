class Solution {
public:
    bool isHappy(int n) {
        if(n==1 || n==7)return true;
        else if(n<10)return false;
        else{
            int sum=0;
        int i=n;
        while(i>0){
             sum = sum+ (i%10)*(i%10);
            i/=10;
        }
        
        return isHappy(sum);
        }
    }
};