class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>&a ,vector<int>& b){
            return a[0]<b[0];
        });
        vector<vector<int>> ans;
        int i=0;
       
        while(i<n){
            if(ans.empty() || intervals[i][0]>ans.back()[1] ){
                ans.push_back(intervals[i]);

            }
            else{
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
            i++;
         
        }
        return ans;
        
    }
};