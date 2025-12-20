class Solution {
public:
    int recsearch(vector<int>& nums,int low,int high,int target){
        if(low>high){
            return -1;

        }
    
        int mid=(low+high)/2;
        if(nums[mid]==target)return mid;
        
        else if(nums[mid]>target)
        return recsearch(nums,low,mid-1,target);
        else 
        return recsearch(nums,mid+1,high,target);
        
    }
    int search(vector<int>& nums, int target) {
        //it is used only for the sorted array and the time complexity for this type of search is log N
        int n =nums.size();
        return recsearch(nums,0,n-1,target);



        //iterative approach
        // int low=0;int high=n-1;
        // while(low<=high){
        //     int mid=(low+high)/2;
        //     if(nums[mid]==target)return mid;

        //     if(nums[mid]<target){
        //         low=mid+1;
        //     }
        //     else{
        //         high=mid-1;
        //     }
        // }
        // return -1;

    }
};