class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0,ml=0;
        while(r<n){
            while(k<0){
                if(nums[l]==0)k++;
                l++;

            }
            if(nums[r]==0){
              k--;
            }
            while(k<0){
                if(nums[l]==0)k++;
                l++;

            }
            ml=max(ml,r-l+1);
            r++;
            
            
        }
        return ml;
        
    }
};