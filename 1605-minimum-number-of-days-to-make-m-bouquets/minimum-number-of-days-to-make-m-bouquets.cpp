class Solution {
public:
    int findmin(vector<int>& arr){
        int mini=INT_MIN;
        for(int x:arr){
            mini=min(mini,x);
        }
        return mini;
    }

    int findmax(vector<int>& arr){
        int maxi=INT_MIN;
        for(int x:arr){
            maxi=max(maxi,x);
        }
        return maxi;
    }
    bool possible(vector<int>& arr,int day,int m,int k){
        int cnt=0,b=0;
        for(int x:arr){
            if(x<=day)cnt++;
            else{
                b = b+(cnt/k);//no of bouquets
                cnt=0;
            }
            
        }
        b=b+(cnt/k);
        if(b>=m)return true;
        else
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // sort(bloomDay.begin(),bloomDay.end());
        int n=bloomDay.size();
        int ans=-1;
        int low=findmin(bloomDay);
        int high=findmax(bloomDay);
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k)==true){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
            

        }
        return ans;
        
    }
};