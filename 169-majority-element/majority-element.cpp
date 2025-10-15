class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mpp;
        for(int it:nums){
            mpp[it]++;
        }
        int c;

        for(auto et:mpp){
            if(et.second>n/2){
                c=et.first;break;
            }
        }
        return c; 
        
    }
};