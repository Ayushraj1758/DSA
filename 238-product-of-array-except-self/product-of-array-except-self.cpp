class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        long long prod=1;
        for(auto x:nums)prod*=x;
        if(prod==0){
            long long ex=1;
            int it=-1;
            int cnt=0;
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    it=i;
                    cnt++;
                    continue;
                }
                ex*=nums[i];
            }
            if(cnt==1)
            ans[it]=ex;

        
        }
        else{

        for(int i=0;i<n;i++){
            ans[i]=prod/nums[i];
        }
        }
        return ans;
    }
};