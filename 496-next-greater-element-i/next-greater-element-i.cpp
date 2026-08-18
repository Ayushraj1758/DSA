class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        map<int,int> mpp;
        vector<int> ans;
        stack<int>st;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i])st.pop();
            if(st.empty())mpp[nums2[i]]=-1;
            else{
                mpp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);

        }
        for(auto x:nums1){
            ans.push_back(mpp[x]);
        }
        return ans;
    


    }
};