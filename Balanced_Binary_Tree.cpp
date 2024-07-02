class Solution {
public:
    int solve(TreeNode* root)
    {
        if(root == NULL) return 0;
        int left = solve(root -> left);
        if(left == -1) return -1;
        int right = solve(root -> right);
        if(right == -1) return -1;
        if(abs(left - right) > 1) return -1;
        return 1 + max(left,right);
    }

    bool isBalanced(TreeNode* root) {
        int res = solve(root);
        if(res == -1) return false;
        return true;
    }
};