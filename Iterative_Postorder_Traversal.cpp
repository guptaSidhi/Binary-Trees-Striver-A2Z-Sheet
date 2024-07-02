class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        stack <TreeNode*> s;
        vector <int> ans;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* temp = s.top();
            ans.push_back(temp -> val);
            s.pop();

            if(temp -> left) s.push(temp -> left);
            if(temp -> right) s.push(temp -> right);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};