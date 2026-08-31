class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int n=matrix.size();
        int m=matrix[0].size();
        // int r=0;
        // while(target>matrix[i][m-1]){
        //     r=i+1;
        //     i++;
        // }
        // int j=0,c=0;
        // while(target>matrix[r][j]){
        //     c=j+1;
        //     j++;
        // }
        // if(matrix[r][c]==target)return true;
        // else
        // return false;
        
        int low=0;
        int high=n*m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target)return true;
            else if(matrix[row][col]<target)low=mid+1;
            else high=mid-1;

        }
        return false;
    }
};