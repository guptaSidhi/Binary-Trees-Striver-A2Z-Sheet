class Solution {
public:
    bool solve(TreeNode* root1,TreeNode* root2)
    {
        if(root1 == NULL || root2 == NULL) return root1 == root2;
        if(root1 -> val != root2 -> val) return false;
        return solve(root1 -> left, root2 -> right) && solve(root1 -> right, root2 -> left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};