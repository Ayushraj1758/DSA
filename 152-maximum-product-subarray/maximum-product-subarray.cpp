class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int  ans=INT_MIN;
        int pre=1,suff=1;
        // long long ans;
        for(int i=0;i<n;i++){
            if(pre==0)pre=1;
            if(suff==0)suff=1;
            pre=pre * nums[i];
            suff=suff*nums[n-i-1];
            int maxi=max(pre,suff);
            ans=max(ans,maxi);
        }
        return ans;        
           
    }
};