#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long MOD = 1e9 + 7;

        // 10 की पावर्स को पहले से कैलकुलेट (Precompute) करके रख लें
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        // x_prefix[i]: 0 से लेकर i-1 इंडेक्स तक के नॉन-ज़ीरो डिजिट्स से बनी संख्या (with mod)
        vector<long long> x_prefix(n + 1, 0);
        // sum_prefix[i]: 0 से लेकर i-1 इंडेक्स तक के डिजिट्स का योग (Sum)
        vector<long long> sum_prefix(n + 1, 0);
        // nz_count[i]: 0 से लेकर i-1 इंडेक्स तक नॉन-ज़ीरो डिजिट्स की कुल संख्या
        vector<int> nz_count(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';
            
            if (digit != 0) {
                x_prefix[i + 1] = (x_prefix[i] * 10 + digit) % MOD;
                sum_prefix[i + 1] = sum_prefix[i] + digit;
                nz_count[i + 1] = nz_count[i] + 1;
            } else {
                x_prefix[i + 1] = x_prefix[i];
                sum_prefix[i + 1] = sum_prefix[i];
                nz_count[i + 1] = nz_count[i];
            }
        }

        vector<int> res;
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];

            // 1. सबस्ट्रिंग के नॉन-ज़ीरो डिजिट्स का सम निकालना (O(1) time)
            long long current_sum = sum_prefix[r + 1] - sum_prefix[l];

            // 2. सबस्ट्रिंग के नॉन-ज़ीरो डिजिट्स से नंबर 'x' बनाना (O(1) time)
            // फार्मूला: x = (x_prefix[r+1] - x_prefix[l] * 10^(नॉन-ज़ीरो डिजिट्स की संख्या)) % MOD
            int total_nz_in_range = nz_count[r + 1] - nz_count[l];
            
            long long x = (x_prefix[r + 1] - (x_prefix[l] * pow10[total_nz_in_range]) % MOD + MOD) % MOD;

            // 3. फाइनल आंसर: (x * current_sum) % MOD
            long long ans = (x * (current_sum % MOD)) % MOD;
            res.push_back(ans);
        }

        return res;
    }
};
