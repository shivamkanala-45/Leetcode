class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);

            for (int i = 0; i < n; i++)
                parent[i] = i;
        }
        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
        void unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b)
                return;

            if (rank[a] < rank[b]) {
                parent[a] = b;
            } else if (rank[a] > rank[b]) {
                parent[b] = a;
            } else {
                parent[b] = a;
                rank[a]++;
            }
        }
    };
    int findCircleNum(vector<vector<int>>& g) {
        int n=g.size();
        DSU d(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j])
                d.unite(i,j);
            }
        }
        set<int>s;
        for(int i=0;i<n;i++)
        s.insert(d.find(i));
        return s.size();
    }
};