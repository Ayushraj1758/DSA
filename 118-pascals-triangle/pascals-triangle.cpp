class Solution {
public:
    vector<int> ncr(int n){
        vector<int>v;
        long long ans=1;
        v.push_back(ans);
        for(int i=1;i<n;i++){
            ans=ans*(n-i);
            ans=ans/(i);
            v.push_back(ans);
        }
    return v;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>answer;
        for(int i=1;i<=numRows;i++){
            answer.push_back(ncr(i));
        }
      return answer;  
    }
};