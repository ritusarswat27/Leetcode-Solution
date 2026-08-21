class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int , int>>> adj(n + 1);

        for(auto it : times){
            adj[it[0]].push_back({it[1] , it[2]});
        }

        vector<int> signal(n+1 , INT_MAX);
        signal[k] = 0;

        priority_queue< vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        pq.push({0 , k});

        int maxDist = 0;

        while(!pq.empty()) {
            auto it = pq.top();
            int dist = it[0];
            int node = it[1];
            pq.pop();

            if(dist > signal[node]) continue; // y line ko use krna bht zaruri h vrna wrong answer mil jayega 

            maxDist = max(dist , maxDist);

            for(auto it : adj[node]) {
                if(dist + it.second < signal[it.first]) {
                    signal[it.first] = dist + it.second;
                    pq.push({signal[it.first] , it.first});
                }
            }
        }

        for(int i=1; i<=n; i++) if(signal[i] == INT_MAX) return -1;
        return maxDist;
    }
};