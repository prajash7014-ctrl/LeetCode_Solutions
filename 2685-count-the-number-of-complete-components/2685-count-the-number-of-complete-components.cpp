class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             int &nodes, int &edgeCount) {

        vis[node] = 1;
        nodes++;
        edgeCount += adj[node].size();

        for (int nei : adj[node]) {
            if (!vis[nei])
                dfs(nei, adj, vis, nodes, edgeCount);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0;
                int edgeCount = 0;

                dfs(i, adj, vis, nodes, edgeCount);

                edgeCount /= 2;   // each edge counted twice

                if (edgeCount == nodes * (nodes - 1) / 2)
                    ans++;
            }
        }

        return ans;
    }
};