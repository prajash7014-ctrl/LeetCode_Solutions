class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";

        vector<pair<char,int>> blocks;

        for (int i = 0; i < t.size();) {
            int j = i;
            while (j < t.size() && t[j] == t[i]) j++;
            blocks.push_back({t[i], j - i});
            i = j;
        }

        int active = 0;
        for (auto &b : blocks)
            if (b.first == '1')
                active += b.second;

        // remove augmented boundary 1's
        active -= 2;

        int ans = active;

        for (int i = 1; i + 1 < blocks.size(); i++) {
            if (blocks[i].first == '1' &&
                blocks[i - 1].first == '0' &&
                blocks[i + 1].first == '0') {

                int gain = blocks[i - 1].second + blocks[i + 1].second;
                ans = max(ans, active + gain);
            }
        }

        return ans;
    }
};