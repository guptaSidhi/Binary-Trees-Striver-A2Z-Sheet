class Solution {
public: 
    void leftboundary(Node* root,vector <int> &ans)
    {
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL) return;
        ans.push_back(root->data);
        if(root -> left != NULL) leftboundary(root->left,ans);
        else leftboundary(root->right,ans);
    }
    
    void leafboundary(Node* root,vector <int> &ans)
    {
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL)
        {
            ans.push_back(root->data);
            return;
        }
        leafboundary(root -> left,ans);
        leafboundary(root -> right,ans);
    }
    
    void rightboundary(Node* root,vector <int> &ans)
    {
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL) return;
        if(root -> right != NULL) rightboundary(root -> right,ans);
        else rightboundary(root -> left,ans);
        ans.push_back(root -> data);
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector <int> ans;
        ans.push_back(root->data);
        if(root -> left == NULL && root -> right == NULL) return ans;
        leftboundary(root->left,ans);
        leafboundary(root,ans);
        rightboundary(root->right,ans);
        return ans;
    }
};