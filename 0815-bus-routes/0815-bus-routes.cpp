class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        int n = routes.size();
        
        unordered_map<int , vector<int>> adj;
        for(int i=0; i<n; i++) {
            for(auto it : routes[i]) {
                adj[it].push_back(i);
            }
        }

        queue<int> q;
        vector<bool> visited(501 , false);
        for(auto it : adj[source]) {
            q.push(it);
            visited[it] = true;
        }

        int busCount = 1;
        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                int route = q.front();
                q.pop();

                for(auto it : routes[route]) {
                    if(it == target) return busCount;

                    for(auto nextRoute : adj[it]) {
                        if(!visited[nextRoute]) {
                            visited[nextRoute] = true;
                            q.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;    
    }
};