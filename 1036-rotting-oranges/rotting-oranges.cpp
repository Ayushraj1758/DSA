class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0,maxt=0;
        queue<pair<pair<int,int>,int>>q;
        // vector<vector<int>>vis(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    // vis[i][j]=2;
                }
                if(grid[i][j]==1)cnt++;
            }
        }

        while(!q.empty()){
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};

            int r=q.front().first.first;
            int c=q.front().first.second;
            int time=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    q.push({{nr,nc},time+1});
                    grid[nr][nc]=2;
                    cnt--;
                }
            }
            maxt=max(maxt,time);


        }
        if(cnt==0)return maxt;
        else return -1;
        
        
    }
};