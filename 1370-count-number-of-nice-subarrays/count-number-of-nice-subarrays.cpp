class Solution {
public:
    int f(vector<int>&nums ,int goal){
        if(goal<0)return 0;
        int n=nums.size();
        int l=0,r=0,cnt=0,sum=0;
        while(r<n){
            sum+=nums[r]%2;
            while(sum>goal){
                sum-=nums[l]%2;
                l++;
            }
            if(sum<=goal){
                cnt+=(r-l+1);
            }
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>temp(n);
        // for(int i=0;i<n;i++){
        //     if(nums[i]%2==1)temp.push_back(1);
        //     else
        //     temp.push_back(0);
        // }
        return f(nums,k)-f(nums,k-1);
        
    }
};