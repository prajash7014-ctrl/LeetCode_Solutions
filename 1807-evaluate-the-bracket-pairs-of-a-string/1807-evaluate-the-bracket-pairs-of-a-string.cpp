class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }
        string result = "";
        bool inKey = false;
        string currentKey = "";
        for (char c : s) {
            if (c == '(') {
                inKey = true;
                currentKey = "";
            } else if (c == ')') {
                inKey = false;
                if (dict.count(currentKey)) {
                    result += dict[currentKey];
                } else {
                    result += "?";
                }
            } else if (inKey) {
                currentKey += c;
            } else {
                result += c;
            }
        }
        return result;
    }
};