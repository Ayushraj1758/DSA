class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        int n=prerequisites.size();
        // int m=prerequisites[0].size();
        for(int i=0;i<n;i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
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
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            cnt++;
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);

            }
        }
        return cnt==numCourses;


    }
};