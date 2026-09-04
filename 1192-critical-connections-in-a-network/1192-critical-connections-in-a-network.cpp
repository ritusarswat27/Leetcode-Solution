class Solution {
public:
void dfs(int node , int parent , int &timer , vector<int> &discovery , vector<int> &lowest , vector<vector<int>> &result , vector<vector<int>> &adj , vector<bool> &visited) {
    visited[node] = true;
    discovery[node] = lowest[node] = timer++;

    for(auto nbr : adj[node]) {
        if(nbr == parent) continue;
        if(visited[nbr] == false) {
            dfs(nbr , node , timer , discovery , lowest , result , adj , visited);
            lowest[node] = min(lowest[node] , lowest[nbr]);
            //check edge is bridge
            if(lowest[nbr] > discovery[node]){
                result.push_back({node , nbr});
            }
        }
        else{
            //back edge
            lowest[node] = min(lowest[node] , discovery[nbr]);
        }
    }

}

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> visited(n , false);
        vector<int> lowest(n , -1);
        vector<int> discovery(n , -1);
        int parent = -1 , timer = 0;
        vector<vector<int>> result;

        for(int i=0; i<n; i++) {
            if(visited[i] == false) {
                dfs(i , parent , timer , discovery , lowest , result , adj , visited);
            }
        }
        return result;    
    }
};