class Solution {
public:
    int findmax(vector<int>& arr){
        int maxi = INT_MIN;
        for(int x : arr){
            maxi = max(maxi, x);
        }
        return maxi;
    }

    long long fun(vector<int>& piles, int k){
        long long tt = 0;
        for(int x : piles){
            tt += (x + k - 1) / k;   // integer ceil
        }
        return tt;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findmax(piles);

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long hours = fun(piles, mid);

            if(hours <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
