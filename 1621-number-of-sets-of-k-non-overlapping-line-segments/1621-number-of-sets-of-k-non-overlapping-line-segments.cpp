class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {
        vector<vector<long long>> dp(n + k, vector<long long>(2 * k + 1));

        dp[0][0] = 1;

        for (int i = 1; i < n + k; i++) {
            dp[i][0] = 1;

            for (int j = 1; j <= 2 * k; j++) {
                dp[i][j] = dp[i - 1][j];

                if (j <= i)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            }
        }

        return dp[n + k - 1][2 * k];
    }
};