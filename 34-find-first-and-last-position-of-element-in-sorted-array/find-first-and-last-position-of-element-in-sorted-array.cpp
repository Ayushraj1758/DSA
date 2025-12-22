class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=-1;int last=-1;
        first=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        last=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        if(first==n || nums[first]!=target)return {-1,-1};
        else
        return {first,last};
        
    }
};