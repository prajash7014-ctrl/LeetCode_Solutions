class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        sort(a.begin(), a.end());

        // pos[originalIndex] = sorted position
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[a[i].second] = i;
        }

        // component build for reachability
        vector<int> comp(n, 0);
        for (int i = 1; i < n; i++) {
            comp[i] = comp[i - 1];
            if (a[i].first - a[i - 1].first > maxDiff) {
                comp[i]++;
            }
        }

        // far[i] = one jump me maximum right index
        vector<int> far(n);
        int r = 0;
        for (int i = 0; i < n; i++) {
            while (r + 1 < n && a[r + 1].first - a[i].first <= maxDiff) {
                r++;
            }
            far[i] = r;
        }

        int LOG = 0;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = far;

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;
        for (auto &q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];
            if (u > v) swap(u, v);

            // different components => unreachable
            if (comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int steps = 0;
            int cur = u;

            // minimum jumps to reach >= v
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < v) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }

            ans.push_back(steps + 1);
        }

        return ans;
    }
};