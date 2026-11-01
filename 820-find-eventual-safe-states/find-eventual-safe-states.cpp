class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>ans;
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);

            }
        }   
        vector<int>id(n,0);
        for(int i=0;i<n;i++){
            for(int it:adj[i]){
                id[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(id[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);;
            q.pop();
            for(auto it:adj[node]){
                id[it]--;
                if(id[it]==0)q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};