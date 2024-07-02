class Solution {
public:
    int solve(TreeNode* root,int &ans)
    {
        if(root == NULL) return 0;
        int left = solve(root -> left,ans);
        int right = solve(root -> right,ans);
        int op1 = root -> val;
        int op2 = root -> val + left + right;
        int op3 = root -> val + left;
        int op4 = root -> val + right;
        ans = max(ans,max(op1,max(op2,max(op3,op4))));
        return max(op1,max(op3,op4));
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};