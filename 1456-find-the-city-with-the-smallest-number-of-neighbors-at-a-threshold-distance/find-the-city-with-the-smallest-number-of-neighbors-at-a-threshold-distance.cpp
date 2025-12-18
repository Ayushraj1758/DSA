class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        
        // Distance to itself = 0
        for(int i = 0; i < n; i++)
            dist[i][i] = 0;
        
        // Fill edges
        for(auto &e : edges) {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }
        
        // Floyd–Warshall
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int city = -1;
        int minCount = INT_MAX;
        
        // Count reachable cities
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(dist[i][j] <= distanceThreshold)
                    cnt++;
            }
            
            // Tie-breaking by larger index
            if(cnt <= minCount) {
                minCount = cnt;
                city = i;
            }
        }
        
        return city;
    }
};
