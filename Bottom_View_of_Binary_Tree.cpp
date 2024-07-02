class Solution {
  public:
    vector <int> bottomView(Node *root) {
        if(root == NULL) return {};
        map <int,int> mp;
        queue <pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            Node* temp = q.front().first;
            int dis = q.front().second;
            mp[dis] = temp -> data;
            q.pop();
            if(temp -> left) q.push({temp->left,dis-1});
            if(temp -> right) q.push({temp -> right,dis+1});
        }
        
        vector <int> ans;
        for(auto it: mp)
        {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};