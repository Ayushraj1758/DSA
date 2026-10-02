class Solution {
public:
    void dfs(vector<vector<int>>&vis,int r,int c,vector<vector<int>>& board){
        int n=board.size();
        int m=board[0].size();
        vis[r][c]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]==1 && vis[nr][nc]==0){
                dfs(vis,nr,nc,board);
            }
        }
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && vis[i][0]==0)dfs(vis,i,0,grid);
            if(grid[i][m-1]==1 && vis[i][m-1]==0)dfs(vis,i,m-1,grid);
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && vis[0][j]==0)dfs(vis,0,j,grid);
            if(grid[n-1][j]==1 && vis[n-1][j]==0)dfs(vis,n-1,j,grid);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1)cnt++;
            }
        }
        return cnt;
        
    }
};