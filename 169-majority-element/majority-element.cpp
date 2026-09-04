class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        // map<int,int>mpp;
        // for(int it:nums){
        //     mpp[it]++;
        // }
        // int c;

        // for(auto et:mpp){
        //     if(et.second>n/2){
        //         c=et.first;break;
        //     }
        // }
        // return c; 
        int me=nums[0];int cnt=1;
        int x=0;
        for(int i=1;i<n;i++){
            if(me==nums[i]){
                cnt++;
            }
            else{
                cnt--;
                if(cnt==0){
                me=nums[i];
                x=i;
                cnt=1;
                }
            }

        }
        return nums[x];
    }
};