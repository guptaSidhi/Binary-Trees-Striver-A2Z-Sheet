// 1st Approach
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        vector <int> ans;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* temp = q.front();
                if(i == n-1) ans.push_back(temp -> val);
                q.pop();

                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
        }
        return ans;
    }
};

// 2nd Approach
class Solution {
public:
    void solve(TreeNode* root,int level,vector <int> &ans)
    {
        if(root == NULL) return;
        if(level == ans.size()) ans.push_back(root->val);
        solve(root->right,level+1,ans);
        solve(root->left,level+1,ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector <int> ans;
        solve(root,0,ans);
        return ans;
    }
};