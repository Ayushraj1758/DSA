class Solution {

public:
long long s1(vector<int>& arr) {
        long long ans=0;
        int n=arr.size();
        vector<int> nse(n),pse(n);
        stack<int> st;
        stack<int> st2;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            if(st.empty())nse[i]=n;
            else{
                nse[i]=st.top();
            }
            st.push(i);
        }

        for(int i=0;i<n;i++){
            while(!st2.empty() && arr[st2.top()]>arr[i])st2.pop();
            if(st2.empty())pse[i]=-1;
            else{
                pse[i]=st2.top();
            }
            st2.push(i);
        }

        for(int i=0;i<n;i++){
            long  left=i-pse[i];
            long right=nse[i]-i;
            ans=(ans+left*right* arr[i]);
        }
        return ans;
}

long long s2largest(vector<int>& arr) {
        long long ans=0;
        int n=arr.size();
        vector<int> nge(n),pge(n);
        stack<int> st;
        stack<int> st2;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i])st.pop();
            if(st.empty())nge[i]=n;
            else{
                nge[i]=st.top();

            }
            st.push(i);
        }

        for(int i=0;i<n;i++){
            while(!st2.empty() && arr[st2.top()]<arr[i])st2.pop();
            if(st2.empty())pge[i]=-1;
            else{
                pge[i]=st2.top();
            }
            st2.push(i);

        }
        for(int i=0;i<n;i++){
            long  left=i-pge[i];
            long right=nge[i]-i;
            ans=(ans+left*right* arr[i]);
        }
        return ans;
}
    long long subArrayRanges(vector<int>& nums) {
        long long ans=s2largest(nums)-s1(nums);
        return ans;
    }
};