class Solution {
public:
bool check(int m , int i , vector<vector<int>>& graph , vector<int>& color) {
    queue<int> q;
    q.push(i);
    color[i] = 0;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto & it : graph[curr]) {
            if(color[it] == -1) {
                color[it] = !color[curr];
                q.push(it);
            }
            else if(color[it] == color[curr]) return false;
        }      
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();

        vector<int> color(m , -1);

        for(int i=0; i<m; i++) {
            if(color[i] == -1) {
            //    if(check(m , i , graph , color) == false)  return false;


                queue<int> q;
                q.push(i);
                color[i] = 0;

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for(auto &it : graph[node]) {
                        if(color[it] == -1) {
                            q.push(it);
                            color[it] = !color[node];
                        }
                        else if(color[it] == color[node]) return false;
                    }
                }
            }
        }
        return true;    
    }
};