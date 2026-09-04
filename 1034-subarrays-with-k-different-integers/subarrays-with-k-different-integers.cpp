class Solution {
public:
int f(vector<int>& nums, int k){
    int l=0,r=0;
    map<int,int>mpp;
    int cnt=0;
    int n=nums.size();
    while(r<n){
        mpp[nums[r]]++;
        while(mpp.size()>k){
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0)mpp.erase(nums[l]);
            l++;
        }
        if(mpp.size()<=k)cnt+=(r-l+1);
        r++;
    }
    return cnt;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        // map<int,int>mpp;
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     mpp.clear();
        //     for(int j=i;j<n;j++){
        //         mpp[nums[j]]++;
        //         if(mpp.size()==k){
        //             cnt++;
        //         }
        //         if(mpp.size()>k)break;
        //     }
        // }
        // return cnt;
        
        //two pointer 
        return f(nums,k)-f(nums,k-1);
    }
};