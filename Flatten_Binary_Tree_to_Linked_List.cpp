class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr != NULL)
        {
            if(curr -> left == NULL) curr = curr -> right;
            else
            {
                TreeNode* prev = curr -> left;
                while(prev -> right != NULL) prev = prev -> right;
                prev -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = NULL;
            }
        }
    }
};