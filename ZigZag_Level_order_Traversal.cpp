class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<vector<int>> ans;
        queue <TreeNode*> q;
        q.push(root);
        bool swap = false;
        while(!q.empty())
        {
            int n = q.size();
            vector <int> temp;
            for(int i=0;i<n;i++)
            {
                TreeNode* top = q.front();
                q.pop();
                temp.push_back(top -> val);
                if(top -> left != NULL) q.push(top -> left);
                if(top -> right != NULL) q.push(top -> right);
            }
            if(swap == false) ans.push_back(temp);
            else 
            {
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            swap = !swap;
        }
        return ans;
    }
};