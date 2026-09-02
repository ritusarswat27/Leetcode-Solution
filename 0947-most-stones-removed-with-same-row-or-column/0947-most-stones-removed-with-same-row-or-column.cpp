class Disjoint {
public:
    vector<int> parent , size , rank;
    Disjoint(int n) {
        parent.resize(n + 1);
        size.resize(n + 1 , 1);
        rank.resize(n + 1 , 0);
        
        for(int i=0; i<=n; i++) parent[i] = i;
};
    
    int findUltimateParent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
    
    void unionByRank(int u , int v) {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);
        
        if(pu == pv) return;
        else if(rank[pu] < rank[pv]) parent[pu] = pv;
        else if(rank[pu] > rank[pv]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    
    void unionBySize(int u , int v) {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);
        
        if(pu == pv) return;
        else if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int maxRow = 0 , maxCol = 0;
        for(auto it : stones) {
            maxRow = max(maxRow , it[0]);
            maxCol = max(maxCol , it[1]);
        }

        Disjoint ds(maxRow + maxCol + 1);
        unordered_map<int , int> stoneNodes;
        for(auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow , nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int components = 0;
        for(auto it : stoneNodes) {
            if(ds.findUltimateParent(it.first) == it.first) components++;
        }
        return n - components;    
    }
};