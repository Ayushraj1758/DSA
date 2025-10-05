class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,maxn=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
                maxn=max(maxn,count);
            }
            else{
            // if(count>maxn)maxn=count;
            count=0;
            }
        }
        return maxn;
        
    }
};