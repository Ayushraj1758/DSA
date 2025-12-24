class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        // if(n==1)return nums[0];
        for(int  i=0;i<n;i++){
            x ^=nums[i];
        }
        return x;
        
    }
};