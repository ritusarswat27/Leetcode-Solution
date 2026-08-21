class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int , int>>> adj(n);
        for(auto it : flights) {
            adj[it[0]].push_back({it[1] , it[2]});
        }

        vector<int> distance(n , INT_MAX);
        distance[src] = 0;

        // queue<pair<int , pair<int , int>>> q;
        // q.push({0 , {src , 0}});

        priority_queue< vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        pq.push({0 , src , 0});

        while(!pq.empty()) {
            // int stop = q.front().first;
            // int node = q.front().second.first;
            // int cost = q.front().second.second;
            // q.pop();

            auto it = pq.top();
            int stop = it[0];
            int node = it[1];
            int cost = it[2];
            pq.pop();

            if(stop > k) continue;
            
            for(auto it : adj[node]) {
                if(cost + it.second < distance[it.first]) {
                    distance[it.first] = cost + it.second;
                    // q.push({stop + 1 , {it.first , distance[it.first]}});
                    pq.push({stop + 1 , it.first , distance[it.first]});
                }
            }   
        }
        return (distance[dst] == INT_MAX) ? -1 : distance[dst];   
    }
};