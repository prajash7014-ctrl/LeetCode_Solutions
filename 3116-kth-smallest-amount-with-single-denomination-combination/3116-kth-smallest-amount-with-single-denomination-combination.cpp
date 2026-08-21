class Solution {
public:
    long long count(long long x, vector<int>& coins) {
        int n = coins.size();
        long long ans = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            long long lcm = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    long long g = gcd(lcm, (long long)coins[i]);
                    lcm = lcm / g * coins[i];

                    // LCM is already greater than x
                    if (lcm > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid) continue;

            long long cnt = x / lcm;

            if (bits & 1)
                ans += cnt;
            else
                ans -= cnt;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long lo = 1;
        long long hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (count(mid, coins) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};