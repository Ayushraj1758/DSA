class Solution {
    public:
    void combination(int ind,vector<int>temp,vector<vector<int>>& ans,vector<int>& candidates,int n,int target){
        if(ind==n){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(candidates[ind]<=target){
            temp.push_back(candidates[ind]);
            // target-=candidates[ind];
            combination(ind,temp,ans,candidates,n,target-candidates[ind]);
            temp.pop_back();
        }
      
        combination(ind+1,temp,ans,candidates,n,target);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int ind=0;

        int n=candidates.size();
        combination(ind,temp,ans,candidates,n,target);
        return ans;
        
    }
};