class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> pmax(n),smax(n);
        pmax[0]=height[0];
        smax[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            pmax[i]=max(pmax[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            smax[i]=max(smax[i+1],height[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            int leftmax=pmax[i];
            int rightmax=smax[i];
            int amax=min(leftmax,rightmax);
            sum+=amax-height[i];
        }
        return sum;
        
    }
};