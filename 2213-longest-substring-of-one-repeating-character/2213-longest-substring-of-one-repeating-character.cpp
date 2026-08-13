using namespace std;
struct Node {
int pref;
int suff;
int best;
int len;
char leftChar;
char rightChar;
}
;
class Solution {
    private:
    int n;
    vector<Node> tree;
    void build(int node, int start, int end, const string& s) {
    if (start == end) {
    tree[node] = {
    1, 1, 1, 1, s[start], s[start]}
    ;
    return;
    }
    int mid = start + (end - start) / 2;
    build(2 * node, start, mid, s);
    build(2 * node + 1, mid + 1, end, s);
    tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int node, int start, int end, int idx, char ch) {
    if (start == end) {
    tree[node] = {
    1, 1, 1, 1, ch, ch}
    ;
    return;
    }
    int mid = start + (end - start) / 2;
    if (idx <= mid) {
    update(2 * node, start, mid, idx, ch);
    }
    else {
    update(2 * node + 1, mid + 1, end, idx, ch);
    }
    tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
    Node combine(const Node& left, const Node& right) {
    Node res;
    res.len = left.len + right.len;
    res.leftChar = left.leftChar;
    res.rightChar = right.rightChar;
    res.pref = left.pref;
    if (left.pref == left.len && left.rightChar == right.leftChar) {
    res.pref += right.pref;
    }
    res.suff = right.suff;
    if (right.suff == right.len && right.leftChar == left.rightChar) {
    res.suff += left.suff;
    }
    res.best = max(left.best, right.best);
    if (left.rightChar == right.leftChar) {
    res.best = max(res.best, left.suff + right.pref);
    }
    return res;
    }
    public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
    n = s.length();
    tree.resize(4 * n);
    build(1, 0, n - 1, s);
    vector<int> ans;
    int k = queryIndices.size();
    for (int i = 0;
    i < k;
    i++) {
    update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
    ans.push_back(tree[1].best);
    }
    return ans;
    }
    }
    ;

