class Solution {
public:
    int find(vector <int> &in,int value,int start,int end)
    {
        for(int i=start;i<=end;i++)
        {
            if(in[i] == value) return i;
        }
        return -1;
    }
    
    TreeNode* solve(vector <int> &pre,vector <int> &in,int pres,int pred,int ins,int ind)
    {
        if(pres > pred || ins > ind) return NULL;
        TreeNode* root = new TreeNode(pre[pres]);
        int index = find(in,root->val,ins,ind);
        if(index == -1) return NULL;

        int num = index - ins;
        root -> left = solve(pre,in,pres+1,pres+num,ins,index-1);
        root -> right = solve(pre,in,pres+num+1,pred,index+1,ind);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0) return NULL;
        int prestart = 0, preend = preorder.size()-1;
        int instart = 0,ineend = inorder.size()-1;
        return solve(preorder,inorder,prestart,preend,instart,ineend);
    }
};