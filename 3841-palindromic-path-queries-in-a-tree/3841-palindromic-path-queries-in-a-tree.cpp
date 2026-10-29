
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tin(n), tout(n), depth(n), parent(n);
        vector<int> euler;
        int timer = 0;

        function<void(int, int)> dfs = [&](int u, int p) {
            parent[u] = p;
            tin[u] = timer++;
            euler.push_back(u);

            for (int v : adj[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }

            tout[u] = timer - 1;
        };

        dfs(0, -1);

        int LOG = 17;
        vector<vector<int>> up(LOG, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
            up[0][i] = parent[i];

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (up[j - 1][i] != -1)
                    up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j))
                    u = up[j][u];
            }

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return parent[u];
        };

        vector<int> bit(n + 1, 0);

        auto add = [&](int idx, int val) {
            for (idx++; idx <= n; idx += idx & -idx)
                bit[idx] ^= val;
        };

        auto get = [&](int idx) {
            int res = 0;
            for (idx++; idx > 0; idx -= idx & -idx)
                res ^= bit[idx];
            return res;
        };

        vector<int> charMask(n);

        for (int i = 0; i < n; i++) {
            charMask[i] = 1 << (s[i] - 'a');
            add(tin[i], charMask[i]);
            add(tout[i] + 1, charMask[i]);
        }

        vector<bool> ans;

        for (string &q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int newMask = 1 << (c - 'a');
                int change = charMask[u] ^ newMask;

                add(tin[u], change);
                add(tout[u] + 1, change);

                charMask[u] = newMask;
                s[u] = c;
            } else {
                int v;
                ss >> v;

                int l = lca(u, v);

                int maskU = get(tin[u]);
                int maskV = get(tin[v]);

                int pathMask = maskU ^ maskV ^ charMask[l];

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};
