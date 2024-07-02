class Solution {
public:
    int leftheight(TreeNode* root)
    {
        int height = 0;
        while(root != NULL)
        {
            height++;
            root = root -> left;
        }
        return height;
    }

    int rightheight(TreeNode* root)
    {
        int height = 0;
        while(root != NULL)
        {
            height++;
            root = root -> right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if(root == NULL) return 0; 
        int left = leftheight(root);
        int right = rightheight(root);
        if(left == right) return pow(2,left)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};