class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int i = 0; i < nums.size(); i++) {
            vector<long long> newdp(k, 0);

            // Subarray containing only nums[i]
            newdp[nums[i] % k]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int rem = (r * (nums[i] % k)) % k;
                    newdp[rem] += dp[r];
                }
            }

            // Add current subarrays to answer
            for (int r = 0; r < k; r++) {
                result[r] += newdp[r];
            }

            dp = newdp;
        }

        return result;
    }
};