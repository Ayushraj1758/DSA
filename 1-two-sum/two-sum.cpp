class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        // map<int ,int>mpp;
        // for(int i=0;i<n;i++){
        //     int a=nums[i];
        //     int more=target-a;
        //     if(mpp.find(more)!=mpp.end())return {mpp[more],i};

        //     mpp[a]=i;
        // }
        // return {-1,-1};

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target)return {i,j};
            }
        }
        return {-1,-1};

    }
};
