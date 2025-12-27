class Solution {
public:
    int findmax(vector<int>& arr, int n){
        int max1=INT_MIN;
        for(int i=0;i<n;i++){
            max1=max(max1,arr[i]);
        }
        return max1;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int ans=INT_MAX;
        int max1=findmax(nums,n);
        int low=1;int high=max1;
        while(low<=high){
            int mid=(low+high)/2;
            long long sum=0;
            for(int i=0;i<n;i++){
                sum+=ceil((double)nums[i]/(double)mid);
            }
            if(sum<=threshold){

                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};