
class Solution {
public:
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(level(root->left),level(root->right));
    }
    void solve(TreeNode* root, vector<int>& store, int initial_level, int final_level){
        if(root==NULL) return;
        if(initial_level==final_level){
            store.push_back(root->val);
            return;
        }
        solve(root->left,store,initial_level+1,final_level);
         solve(root->right,store,initial_level+1,final_level);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> store;
        int a = level(root);
        for(int i=0;i<a;i++){
        solve(root,store,1,i+1);
        result.push_back(store);
        store.clear();
        }
        return result;
    }
};