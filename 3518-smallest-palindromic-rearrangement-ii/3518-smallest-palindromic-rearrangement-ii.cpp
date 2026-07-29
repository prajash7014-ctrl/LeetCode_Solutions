class Solution {
public:
    using ll = long long;
    const ll LIM = 1000000LL;

    // C(n,r), capped at limit
    ll comb(int n, int r, ll limit) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);

        ll ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans >= limit) return limit;
        }
        return ans;
    }

    // Count distinct permutations of multiset
    ll countWays(vector<int> &freq, ll limit) {
        int rem = 0;
        for (int x : freq) rem += x;

        ll ans = 1;
        int left = rem;

        for (int f : freq) {
            if (f == 0) continue;
            ans *= comb(left, f, limit);
            if (ans >= limit) return limit;
            left -= f;
        }

        return min(ans, limit);
    }

    string smallestPalindrome(string s, int k) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        vector<int> half(26, 0);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
            if (cnt[i] & 1)
                mid.push_back(char('a' + i));
        }

        int m = s.size() / 2;
        string left = "";

        for (int pos = 0; pos < m; pos++) {

            bool found = false;

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0) continue;

                half[c]--;

                ll ways = countWays(half, k);

                if (ways < k) {
                    k -= ways;
                    half[c]++;
                } else {
                    left.push_back(char('a' + c));
                    found = true;
                    break;
                }
            }

            if (!found) return "";
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};