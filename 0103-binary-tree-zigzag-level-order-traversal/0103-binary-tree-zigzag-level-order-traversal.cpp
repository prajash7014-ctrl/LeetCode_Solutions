class Solution {
public:
 int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(level(root->left),level(root->right));
    }
    void solve1(TreeNode* root, vector<int>& store, int initial_level, int final_level){
        if(root==NULL) return;
        if(initial_level==final_level){
            store.push_back(root->val);
            return;
        }
        solve1(root->left,store,initial_level+1,final_level);
         solve1(root->right,store,initial_level+1,final_level);
    }
    void solve2(TreeNode* root, vector<int>& store, int initial_level, int final_level){
        if(root==NULL) return;
        if(initial_level==final_level){
            store.push_back(root->val);
            return;
        }
        solve2(root->right,store,initial_level+1,final_level);
        solve2(root->left,store,initial_level+1,final_level);
         
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> store;
        int a = level(root);
        for(int i=0;i<a;i++){
        solve1(root,store,1,i+1);
        result.push_back(store);
         store.clear();
         i+=1;
        solve2(root,store,1,i+1);
        if(!store.empty()){
        result.push_back(store);
        }
        store.clear();
        }
        return result;
    }
};


