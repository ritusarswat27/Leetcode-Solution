class Disjoint {
public:
    vector<int> parent , rank , size;
    Disjoint(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1 , 0);
        size.resize(n + 1 , 1);

        for(int i=0; i<=n; i++) parent[i] = i;
    }
   
    int findUltimateParent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u , int v) {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);

        if(pu == pv) return;
        else if(rank[pu] < rank[pv]) parent[pu] = pv;
        else if(rank[pv] < rank[u]) parent[pv] = pu;
        else{
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
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        Disjoint ds(n * n);

        int maxSize = 0;

        int dRow[] = {-1 , 0 , 1 , 0};
        int dCol[] = {0 , 1 , 0 , -1};

        for(int row=0; row<n; row++) {
            for(int col=0; col<n; col++) {
                if(grid[row][col] == 1) {
                    for(int i=0; i<4; i++) {
                        int nRow = row + dRow[i];
                        int nCol = col + dCol[i];
                        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1) {
                            int nodeNo = (row * n) + col;
                            int adjNodeNo = (nRow * n) + nCol;
                            ds.unionBySize(nodeNo , adjNodeNo);
                        }
                    }
                }
            }
        } 

        for(int row=0; row<n; row++) {
            for(int col=0; col<n; col++) {
                if(grid[row][col] == 0) {
                    set<int> components;
                    for(int i=0; i<4; i++) {
                        int nRow = row + dRow[i];
                        int nCol = col + dCol[i];
                        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1) {
                            components.insert(ds.findUltimateParent((nRow * n) + nCol));
                        }
                    }
                    int sizeTotal = 1;
                    for(auto it : components) sizeTotal += ds.size[it];
                    maxSize = max(maxSize , sizeTotal);
                }
            }
        }

        for(int cell = 0; cell < n * n; cell++) {
            if(grid[cell / n][cell % n] == 1) {
                maxSize = max(maxSize, ds.size[ds.findUltimateParent(cell)]);
            }
        }
        return maxSize;    
    }
};