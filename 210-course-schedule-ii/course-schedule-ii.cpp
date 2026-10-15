class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
     vector<int> adj[numCourses];
        int n=prerequisites.size();
        // int m=prerequisites[0].size();
        for(int i=0;i<n;i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        //topo sort

        vector<int>ans;
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        
        while(!q.empty()){
            int node=q.front();
            
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);

            }
            ans.push_back(node);
        }
        if(ans.size()==numCourses)return ans;
        return {};
   
    }
};