class Solution {
public:
int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int , int>>> adj(n);
        for(auto it : roads) {
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }

        vector<long long> distance(n , LLONG_MAX);
        distance[0] = 0;

        vector<int> ways(n , 0);
        ways[0] = 1;

        priority_queue<
            pair<long long , int> , 
            vector<pair<long long , int>> , 
            greater<pair<long long , int>>
        > pq;
        pq.push({0 , 0});

        while(!pq.empty()) {
            long long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]) {
                if(dist + it.second < distance[it.first]) {
                    distance[it.first] = dist + it.second;
                    pq.push({distance[it.first] , it.first});
                    ways[it.first] = ways[node];
                }
                else if(dist + it.second == distance[it.first]) {
                    ways[it.first] = (ways[it.first] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};