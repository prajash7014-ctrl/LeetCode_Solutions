class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> res;
        
        // precompute: comp[i] tells which connected segment index i belongs to
        vector<int> comp(n, 0);
        for (int i = 1; i < n; i++) {
            if (abs(nums[i] - nums[i - 1]) <= maxDiff) {
                comp[i] = comp[i - 1];
            } else {
                comp[i] = comp[i - 1] + 1;
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];

            if (comp[a] == comp[b]) res.push_back(true);
            else res.push_back(false);
        }

        return res;
    }
};