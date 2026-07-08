class Solution {
public:
    int f(vector<int> & nums){
        int n=nums.size()-1;
        if(n==0)return nums[n];
        if(n<0)return 0;
        int curi,prev,prev2;
        prev=nums[0];prev2=0;
        for(int i=0;i<=n;i++){
            int pick=nums[i];
            if(i>1)pick+=prev2;
            int notpick=0+prev;
            curi=max(pick,notpick);
            prev2=prev;
            prev=curi;
        }
        return prev;

    }
public:
    int rob(vector<int>& nums) {
        int ind=nums.size()-1;
        if(ind==0)return nums[ind];

        vector<int>temp1,temp2;
        for(int i=0;i<=ind;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=ind)temp2.push_back(nums[i]);
        }
                
        int ans1=f(temp1);
        int ans2=f(temp2);
        return max(ans1,ans2);
    }
};