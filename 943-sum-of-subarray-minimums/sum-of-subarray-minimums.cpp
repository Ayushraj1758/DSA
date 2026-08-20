class Solution {
    const int mod=1000000007;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int ans=0;
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
            ans=(ans+left*right* arr[i])%mod;
        }
        
        return ans ;
        
    }
};