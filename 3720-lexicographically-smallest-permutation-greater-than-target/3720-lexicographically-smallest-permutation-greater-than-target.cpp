class Solution { 
public: 
    string lexGreaterPermutation(string s, string target) { 
        int n = s.size();

        // Frequency of characters in s
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Store remaining frequency after matching
        // target prefix
        vector<vector<int>> remain(n + 1, vector<int>(26));
        remain[0] = freq;

        int valid = 0;

        // Try to match target prefix
        for (int i = 0; i < n; i++) {
            remain[i + 1] = remain[i];

            int ch = target[i] - 'a';

            if (remain[i + 1][ch] == 0) {
                break;
            }

            remain[i + 1][ch]--;
            valid = i + 1;
        }

        // Try to make the first greater character
        // as far right as possible
        for (int i = valid; i >= 0; i--) {

            vector<int> temp = remain[i];

            // Find smallest character > target[i]
            if (i == n) continue;

            for (int ch = target[i] - 'a' + 1; ch < 26; ch++) {
                if (temp[ch] > 0) {

                    string ans = target.substr(0, i);

                    // Add greater character
                    ans += char('a' + ch);
                    temp[ch]--;

                    // Add remaining characters in sorted order
                    for (int j = 0; j < 26; j++) {
                        ans += string(temp[j], char('a' + j));
                    }

                    return ans;
                }
            }
        }

        return "";
    } 
};