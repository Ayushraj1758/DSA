class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int sum=n*(n+1)/2;
        for(int i=0;i<n;i++){
            s=s+nums[i];
        }
        return(sum-s);
    }
};