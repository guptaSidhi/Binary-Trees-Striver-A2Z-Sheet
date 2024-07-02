class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        queue<TreeNode*> q;
        q.push(root);
        mp[root] = nullptr;
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (curr->left) {
                q.push(curr->left);
                mp[curr->left] = curr;
            }
            
            if (curr->right) {
                q.push(curr->right);
                mp[curr->right] = curr;
            }
        }
        
        queue<pair<TreeNode*, int>> q1;
        q1.push({target, 0});
        
        vector<int> ans;
        unordered_set<TreeNode*> visited;
        
        while (!q1.empty()) {
            TreeNode* curr = q1.front().first;
            int dis = q1.front().second;
            q1.pop();
            
            visited.insert(curr);
            
            if (dis == k) {
                ans.push_back(curr->val);
                continue;
            }
            
            if (curr->left && visited.find(curr->left) == visited.end()) {
                q1.push({curr->left, dis + 1});
            }
            
            if (curr->right && visited.find(curr->right) == visited.end()) {
                q1.push({curr->right, dis + 1});
            }
            
            TreeNode* parent = mp[curr];
            if (parent && visited.find(parent) == visited.end()) {
                q1.push({parent, dis + 1});
            }
        }
        
        return ans;
    }
};