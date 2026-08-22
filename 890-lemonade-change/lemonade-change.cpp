class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
    
        int x5=0,x10=0,x20=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                x5++;
            }
            else if(bills[i]==10){
                if(x5>0){
                    x10++;
                    x5--;
                }
                else return false;
            }
                else{
                    if(x5>0 && x10>0){
                        x10--;x5--;

                    }
                    else if(x5>=3)x5-=3;
                else
                return false;
            }
        }
        return true;
        
    }
};