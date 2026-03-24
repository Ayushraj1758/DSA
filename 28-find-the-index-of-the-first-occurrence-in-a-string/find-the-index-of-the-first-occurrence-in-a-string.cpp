class Solution {
public:
    int strStr(string haystack, string needle) {
        int n =needle.size();
        int m =haystack.size();
        int i=0;
        while(i<=m-n){
           int j=0;while(j<n){
            if(haystack[i+j]!=needle[j]){
                break;
            }j++;
           }
           if(j==n)return i;
           i++;
        }
        return -1;
    }
};