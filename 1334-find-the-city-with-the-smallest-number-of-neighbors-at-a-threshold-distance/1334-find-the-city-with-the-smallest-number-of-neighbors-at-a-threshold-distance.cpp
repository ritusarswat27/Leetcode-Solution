class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n , vector<int>(n , INT_MAX));

        for(int i=0; i<n; i++) dist[i][i] = 0;

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for(int via=0; via<n; via++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(dist[i][via] != INT_MAX && dist[via][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j] , dist[i][via] + dist[via][j]);
                    }
                }
            }
        }
        int minReachableCities = INT_MAX;
        int bestCity = -1;

        for(int i=0; i<n; i++) {
            int reachableCities = 0;
            for(int j=0; j<n; j++) {
                if(dist[i][j] <= distanceThreshold) reachableCities++;
            }
            if (reachableCities <= minReachableCities) {
                minReachableCities = reachableCities;
                bestCity = i;
            }
        }
        return bestCity;   
    }
};