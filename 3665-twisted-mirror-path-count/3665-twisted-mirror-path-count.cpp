class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int MOD = 1e9 + 7;

        vector<vector<array<int, 2>>> memo(
            m, vector<array<int, 2>>(n, {-2, -2})
        );

        // dir = 0: moving right
        // dir = 1: moving down
        function<int(int, int, int)> getNext =
        [&](int i, int j, int dir) -> int {

            if(i >= m || j >= n)
                return -1;

            if(grid[i][j] == 0)
                return i * n + j;

            if(memo[i][j][dir] != -2)
                return memo[i][j][dir];

            int ans;

            if(dir == 0) {
                ans = getNext(i + 1, j, 1);
            }
            else {
                ans = getNext(i, j + 1, 0);
            }

            return memo[i][j][dir] = ans;
        };

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1 || dp[i][j] == 0)
                    continue;

                // Try moving right
                int r = getNext(i, j + 1, 0);

                if(r != -1) {
                    int x = r / n;
                    int y = r % n;

                    dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                }

                // Try moving down
                int d = getNext(i + 1, j, 1);

                if(d != -1) {
                    int x = d / n;
                    int y = d % n;

                    dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m-1][n-1];
    }
};