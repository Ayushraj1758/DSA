class Solution {
    private:
    bool bfs(int start,vector<int>&color ,vector<vector<int>>& graph ){
        queue<int>q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto el:graph[node]){
                if(color[el]==-1){
                    color[el]=!color[node];
                    q.push(el);
                }
                else if(color[el]==color[node])return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1)
            if(bfs(i,color,graph)==false)return false;
        }
        return true;
        
    }
};