class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     set<int> st;int cnt=0;
        //     for(int j=i;j<n;j++){
        //         if(st.size()<2 || st.find(fruits[j])!=st.end()){
        //         st.insert(fruits[j]);
        //         cnt++;
        //         ans=max(ans,cnt);
        //         }
        //     }
        // }
        // return ans;


        //two pointer approach
        int l=0,r=0,ml=0;
        map<int,int> mpp;
        while(r<n){
            mpp[fruits[r]]++;
            
                while(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0)mpp.erase(fruits[l]);
                l++;
            }
            
            if(mpp.size()<=2)ml=max(ml,r-l+1);
            r++;
        }
        return ml;

    }
};