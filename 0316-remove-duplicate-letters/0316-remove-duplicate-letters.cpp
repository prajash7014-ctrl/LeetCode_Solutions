class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26);
        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        vector<bool> vis(26, false);
        string ans;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (vis[c - 'a']) continue;

            while (!ans.empty() &&
                   ans.back() > c &&
                   last[ans.back() - 'a'] > i) {
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(c);
            vis[c - 'a'] = true;
        }

        return ans;
    }
};