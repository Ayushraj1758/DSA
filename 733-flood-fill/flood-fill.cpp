class Solution {
public:
    void dfs(vector<vector<int>>& t, int r, int c, int color,int dr[],int dc[],int initial){
        // int temp=t[r][c];
        t[r][c]=color;
        int n=t.size();
        int m=t[0].size();
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && t[nr][nc]==initial){
                dfs(t,nr,nc,color,dr,dc,initial);
                // t[nr][nc]=color;
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> t=image;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int initial=image[sr][sc];
        if (initial ==color)return t;
        dfs(t,sr,sc,color,dr,dc,initial);
        return t;
    }
};