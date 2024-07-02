class Solution{
    public:
    int solve(Node* root)
    {
        if(root == NULL) return 0;
        if(!root->left && !root->right) return root->data;
        int left = solve(root->left);
        if(left == -1) return -1;
        int right = solve(root->right);
        if(right == -1) return -1;
        if(left + right != root -> data) return -1;
    }
    
    int isSumProperty(Node *root)
    {
        if(solve(root) != -1) return true;
        return false;
    }
};