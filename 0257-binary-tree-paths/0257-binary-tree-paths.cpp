class Solution {
public:
    void helper(TreeNode* root, string store, vector<string>& s){
        if(root==NULL) return;
        string a = to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            store+=a;
            s.push_back(store);
            return;
        }
        helper(root->left,store+a+"->",s);
        helper(root->right,store+a+"->",s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
     vector<string> s;
     helper(root,"",s);
     return s;   
    }
};