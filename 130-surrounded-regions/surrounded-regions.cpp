class Solution {
public:
    void dfs(vector<vector<int>>&vis,int r,int c,vector<vector<char>>& board){
        int n=board.size();
        int m=board[0].size();
        vis[r][c]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='O' && vis[nr][nc]==0){
                dfs(vis,nr,nc,board);
            }
        }
        
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && vis[i][0]==0)dfs(vis,i,0,board);
            if(board[i][m-1]=='O' && vis[i][m-1]==0)dfs(vis,i,m-1,board);
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && vis[0][j]==0)dfs(vis,0,j,board);
            if(board[n-1][j]=='O' && vis[n-1][j]==0)dfs(vis,n-1,j,board);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 )board[i][j]='X';
            }
        }

        
    }
};