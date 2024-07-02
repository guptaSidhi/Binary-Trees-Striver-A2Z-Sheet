class Solution {
  public:
    void solve(Node* root,vector <int> &temp, vector<vector<int>> &ans)
    {
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL) 
        {
            temp.push_back(root->data);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        if(root -> left) 
        {
            temp.push_back(root->data);
            solve(root->left,temp,ans);
            temp.pop_back();
        }
        
        if(root -> right)
        {
            temp.push_back(root->data);
            solve(root->right,temp,ans);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector <int> temp;
        solve(root,temp,ans);
        return ans;
    }
};