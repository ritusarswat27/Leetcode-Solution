class Solution {
public:                
    //             check[node] = 0;                      
    //         check[node] = 0;       
    // check[node] = 1;
bool dfs(int node , vector<bool>& visited , vector<bool>& pathVisited , vector<vector<int>>& graph , vector<bool>& check) {
    visited[node] = true;
    pathVisited[node] = true;

    for(auto it : graph[node]) {
        if(!visited[it]) {
            if(dfs(it , visited , pathVisited , graph , check) == true) {
                check[it] = false;
                return true;
            }
        }
        else if(pathVisited[it]) {
            check[it] = false;
            return true;
        }
    }

    pathVisited[node] = false;
    check[node] = true;
    return false;
}

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n , false);
        vector<bool> pathVisited(n , false);
        vector<bool> check(n , false);
        vector<int> safeNodes;

        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(i , visited , pathVisited , graph , check);
            }
        }

        for(int i=0; i<n; i++) if(check[i] == true) safeNodes.push_back(i);

        return safeNodes;
    }
};