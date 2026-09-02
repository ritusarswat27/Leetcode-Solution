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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        unordered_map<string , int> mpp;
        Disjoint ds(n);

        for(int i=0; i<n; i++) {
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mpp.find(mail) == mpp.end()) mpp[mail] = i;
                else ds.unionBySize(i , mpp[mail]);
            }
        }

        vector<string> mergeMail[n];
        for(auto it : mpp) {
            string mail = it.first;
            int node = ds.findUltimateParent(it.second);
            mergeMail[node].push_back(mail);
        }
        
        vector<vector<string>> answer;
        for(int i=0; i<n; i++) {
            if(mergeMail[i].size() == 0) continue;
            sort(mergeMail[i].begin() , mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergeMail[i]) temp.push_back(it);
            answer.push_back(temp);
        }
        return answer;
    }
};