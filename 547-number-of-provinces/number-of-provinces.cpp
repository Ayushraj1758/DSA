class Solution {
public:
    void bfs(int start,vector<int>adj[],vector<int>&vis){
        queue<int>q;
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto x:adj[node]){
                if(vis[x]==0){
                    vis[x]=1;
                    q.push(x);
                }

            }
        }
        return ;


    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        int v1=isConnected[0].size();
        vector<int>adj[v];
        for(int i=0;i<v;i++){
            vector<int>temp;
            for(int j=0;j<v1;j++){
                if(isConnected[i][j]==1 && i!=j)
                temp.push_back(j);

            }
            adj[i]=temp;
        }
        int cnt=0;
        vector<int>vis(v,0);
        for(int i=0;i<v;i++){
            if(vis[i]==0){
                cnt++;
                bfs(i,adj,vis);
            }
        }
        return cnt;

        
    }
};