class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root,0});
        int maxi = 0;
        while(!q.empty())
        {
            int n = q.size();
            unsigned long long first = 0, second = 0;
            for(int i=0;i<n;i++)
            {
                TreeNode* temp = q.front().first;
                unsigned long long dis = q.front().second;
                q.pop();
                if(i == 0) first = dis;
                if(i == n-1) second = dis;

                if(temp -> left) 
                    q.push({temp -> left,2*dis});
                if(temp -> right)
                    q.push({temp -> right,2*dis+1});
            }
            maxi = max(maxi,int(second-first+1));
        }
        return maxi;
    }
};