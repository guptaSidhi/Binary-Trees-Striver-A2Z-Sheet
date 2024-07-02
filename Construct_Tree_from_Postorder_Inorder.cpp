class Solution {
public:
    int find(vector <int> &in,int start,int end,int value)
    {
        for(int i=start;i<=end;i++)
        {
            if(in[i] == value) return i;
        }
        return -1;
    }

    TreeNode* solve(vector <int> &inorder,vector <int> &postorder,int ins,int ind,int posts,int postd)
    {
        if(ins > ind || posts > postd) return NULL;
        TreeNode* root = new TreeNode(postorder[postd]);
        int index = find(inorder,ins,ind,root->val);
        if(index == -1) return NULL;
        int num = index - ins;
        root -> left = solve(inorder,postorder,ins,index-1,posts,posts+num-1);
        root -> right = solve(inorder,postorder,index+1,ind,posts+num,postd-1);
        return root;
    }   

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return NULL;
        return solve(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};