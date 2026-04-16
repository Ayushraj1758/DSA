class Solution {
public:
    void subs(int ind,vector<int>& nums, set<vector<int>>& ans,vector<int>& temp,int n){
        if(ind==n){
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[ind]);
        subs(ind+1,nums,ans,temp,n);
        temp.pop_back();
        subs(ind+1,nums,ans,temp,n);

    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int>temp;
        int n=nums.size();
        subs(0,nums,ans,temp,n);
        vector<vector<int>>fans;
        for(auto x:ans){

            fans.push_back(x);
        }
        return fans;
        
    }
};