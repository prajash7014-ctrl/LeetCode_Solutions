class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Convert to prefix sums
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        // Taking all stones is always a possible final move
        int dp = stones[n - 1];

        // Try all possible first moves
        for (int i = n - 2; i > 0; i--) {
            dp = max(dp, stones[i] - dp);
        }

        return dp;
    }
};