class Solution {
public:

    set<string> parse(string &s, int &i) {

        set<string> ans;
        set<string> cur = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                // Union
                for (auto x : cur)
                    ans.insert(x);

                cur = {""};
                i++;
            }

            else if (s[i] == '{') {

                i++; // skip '{'

                set<string> temp = parse(s, i);

                i++; // skip '}'

                // Concatenate cur and temp
                set<string> next;

                for (auto a : cur) {
                    for (auto b : temp) {
                        next.insert(a + b);
                    }
                }

                cur = next;
            }

            else {
                // Single character
                char c = s[i];
                i++;

                set<string> next;

                for (auto x : cur) {
                    next.insert(x + c);
                }

                cur = next;
            }
        }

        // Add last expression
        for (auto x : cur)
            ans.insert(x);

        return ans;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> result = parse(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};