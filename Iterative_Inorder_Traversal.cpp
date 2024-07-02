class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return {};

        vector <int> ans;
        stack <TreeNode*> s;
        s.push(root);

        TreeNode* temp = s.top();

        if(temp -> left != NULL) {
            while(temp -> left != NULL) {
                s.push(temp -> left);
                temp = temp -> left;
            }
        }

        while(!s.empty())
        {
            TreeNode* front = s.top();
            ans.push_back(front -> val);
            s.pop();

            if(front -> right != NULL) 
            {
                s.push(front -> right);
                front = front -> right;

                if(front -> left != NULL)
                {
                    while(front -> left != NULL) {
                        s.push(front -> left);
                        front = front -> left;
                    }
                }
            }
        }

        return ans;
    }
};