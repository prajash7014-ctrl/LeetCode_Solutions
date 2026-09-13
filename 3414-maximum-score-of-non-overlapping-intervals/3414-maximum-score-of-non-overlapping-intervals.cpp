class Solution {
public:
    struct Node {
        long long score;
        vector<int> ids;
    };

    bool better(Node &a, Node &b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(a.begin(), a.end());

        vector<long long> starts(n);
        for (int i = 0; i < n; i++)
            starts[i] = a[i][0];

        // next[i] = first interval whose left > a[i].right
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            nxt[i] = upper_bound(
                starts.begin(),
                starts.end(),
                a[i][1]
            ) - starts.begin();
        }

        vector<vector<Node>> dp(n + 1, vector<Node>(5));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                // Don't take
                Node skip = dp[i + 1][k];

                // Take
                Node take = dp[nxt[i]][k - 1];

                take.score += a[i][2];
                take.ids.push_back(a[i][3]);
                sort(take.ids.begin(), take.ids.end());

                if (better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        return dp[0][4].ids;
    }
};