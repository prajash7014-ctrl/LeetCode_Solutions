class Solution {
    private:
    int n;
    vector<int> suffixSum;
    vector<vector<int>> memo;
    int solve(int i, int m, const vector<int>& piles) {
    if (i >= n) {
    return 0;
    }
    if (i + 2 * m >= n) {
    return suffixSum[i];
    }
    if (memo[i][m] != -1) {
    return memo[i][m];
    }
    int maxStones = 0;
    for (int x = 1;
    x <= 2 * m;
    ++x) {
    int opponentStones = solve(i + x, max(m, x), piles);
    int currentStones = suffixSum[i] - opponentStones;
    maxStones = max(maxStones, currentStones);
    }
    return memo[i][m] = maxStones;
    }
    public:
    int stoneGameII(vector<int>& piles) {
    n = piles.size();
    suffixSum = piles;
    for (int i = n - 2;
    i >= 0;
    --i) {
    suffixSum[i] += suffixSum[i + 1];
    }
    memo.assign(n, vector<int>(n + 1, -1));
    return solve(0, 1, piles);
    }
    }
    ;