class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        for(int i = 0; i < n; i++){
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            if(first[s[i] - 'a'] != i)
                continue;

            int l = i;
            int r = last[s[i] - 'a'];
            bool ok = true;

            for(int j = l; j <= r; j++){
                if(first[s[j] - 'a'] < l){
                    ok = false;
                    break;
                }

                r = max(r, last[s[j] - 'a']);
            }

            if(ok)
                ans.push_back({l, r});
        }

        sort(ans.begin(), ans.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });

        vector<string> result;
        int end = -1;

        for(auto x : ans){
            if(x[0] > end){
                result.push_back(s.substr(x[0], x[1] - x[0] + 1));
                end = x[1];
            }
        }

        return result;
    }
};