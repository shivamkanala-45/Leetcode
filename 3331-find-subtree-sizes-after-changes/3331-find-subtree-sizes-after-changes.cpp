
class Solution {
public:
    vector<vector<int>> adj, tree;
    vector<int> last, ans, np;
    void dfs(int u, string& s) {
        int c = s[u] - 'a';
        int old = last[c];
        if (old != -1)
            np[u] = old;

        last[c] = u;

        for (int v : adj[u])
            dfs(v, s);

        last[c] = old;
    }

    int dfs2(int u) {
        int sz = 1;

        for (int v : tree[u])
            sz += dfs2(v);

        ans[u] = sz;
        return sz;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        adj.resize(n);
        tree.resize(n);
        last.assign(26, -1);
        ans.assign(n, 0);
        np = parent;
        for (int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);
        dfs(0, s);
        for (int i = 1; i < n; i++)
            tree[np[i]].push_back(i);
        dfs2(0);

        return ans;
    }
};
