class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            root=node.first;
            int x=node.second.first;
            int y=node.second.second;
            m[x][y].insert(root->val);
            if(root->left)
            {
                q.push({root->left,{x-1,y+1}});
            }
            if(root->right)
            {
                q.push({root->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto i:m){
            vector<int> v;
            for(auto j:i.second){
                v.insert(v.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};