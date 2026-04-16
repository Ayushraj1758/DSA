class Solution {
    public:
    void combination(int x,int k,int n,vector<int>& temp,vector<vector<int>>& ans){
        if(n==0 && k==0){
            ans.push_back(temp);
            return;
        }
        if(k<0 || n<0){
            return;
        }
        for(int i=x;i<=9;i++){
                if(i>n)break;
                temp.push_back(i);
                combination(i+1,k-1,n-i,temp,ans);
                temp.pop_back();
            
        }

    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>temp;
        combination(1,k,n,temp,ans);
        return ans;
    }
};