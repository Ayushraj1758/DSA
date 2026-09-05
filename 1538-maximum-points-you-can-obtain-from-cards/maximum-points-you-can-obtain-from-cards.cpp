class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ts = 0,ls=0,rs=0;

        for(int i=0;i<k;i++)ls+=cardPoints[i];
        ts=ls;
        int ri=n-1;
        for(int i=k-1;i>=0;i--){
            ls-=cardPoints[i];
            rs+=cardPoints[ri];
            ri--;
            ts=max(ls+rs,ts);
        }
        return ts;
    }
};
