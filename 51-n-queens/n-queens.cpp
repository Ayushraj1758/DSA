class Solution {
private:
    void solve(int n,vector<vector<string>>& ans, vector<string>& board,int col,vector<int>& lr,vector<int>& ud,vector<int>& ld){
        if(col==n){
            ans.push_back(board);return;
        }
        for(int row=0;row<n;row++){
            if(lr[row]==0 && ld[row+col]==0 && ud[n-1 + col-row]==0){
            board[row][col]='Q';
            lr[row]=1;ld[row+col]=1;ud[n-1+col-row]=1;
            solve(n,ans,board,col+1,lr,ud,ld);

            board[row][col]='.';
            lr[row]=0;ld[row+col]=0;ud[n-1+col-row]=0;
            
            // solve(n,ans,board,col+1,lr,ud,ld);
            }


        }
    }


public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int>lr(n,0),ld(2*n-1,0),ud(2*n-1,0);

        solve(n,ans,board,0,lr,ud,ld);
        return ans;
    }
};