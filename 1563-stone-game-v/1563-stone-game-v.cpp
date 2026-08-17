class Solution {
public:
    vector<int> prefix;
    vector<vector<int>> memo;

    int rangeSum(int l, int r) {
        return prefix[r + 1] - prefix[l];
    }

    int solve(int l, int r) {
        if (l == r) return 0;

        if (memo[l][r] != -1)
            return memo[l][r];

        int ans = 0;

        for (int k = l; k < r; k++) {
            int left = rangeSum(l, k);
            int right = rangeSum(k + 1, r);

            if (left < right) {
                ans = max(ans, left + solve(l, k));
            }
            else if (left > right) {
                ans = max(ans, right + solve(k + 1, r));
            }
            else {
                ans = max(ans,
                          left + max(solve(l, k), solve(k + 1, r)));
            }
        }

        return memo[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stoneValue[i];

        memo.assign(n, vector<int>(n, -1));

        return solve(0, n - 1);
    }
};