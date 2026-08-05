class Solution {
public:
    void dfs(int v, vector<bool>& vis, vector<vector<int>>& g) {
        vis[v] = true;
        for (auto x : g[v]) {
            if (!vis[x])
                dfs(x, vis, g);
        }
    }
    int find(int x, vector<int>& p) {
        if (p[x] == x)
            return x;
        return p[x] = find(p[x], p);
    }
    void u(int a, int b, vector<int>& r, vector<int>& p) {
        a = find(a, p);
        b = find(b, p);

        if (a == b)
            return;

        if (r[a] < r[b])
            swap(a, b);

        p[b] = a;

        if (r[a] == r[b])
            r[a]++;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& v) {
        vector<int> r(n, 0), p(n);
        for (int i = 0; i < n; i++)
            p[i] = i;
        for (auto x : v)
            u(x[0], x[1], r, p);
        vector<vector<int>> g(n);
        for (auto x : v)
            g[x[0]].push_back(x[1]);
        vector<bool> vis(n, false);
        dfs(k, vis, g);
        bool ff = true;
        vector<int> ans;
        int pp = find(k, p);

        for (int i = 0; i < n; i++) {
            if (find(i, p) == pp && !vis[i])
                ff = false;

            if (!vis[i])
                ans.push_back(i);
        }
        if (ff)
            return ans;
        vector<int> hehe(n);
        for (int i = 0; i < n; i++)
            hehe[i] = i;
        return hehe;
    }
};