class Codec {
public:
    string serialize(TreeNode* root) {
        if (root == NULL) return "#";
        
        string result = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (curr == NULL) {
                result += "#,";
            } else {
                result += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        
        return result;
    }

    TreeNode* deserialize(string data) {
        if (data == "#") return NULL;
        
        stringstream ss(data);
        string token;
        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            getline(ss, token, ',');
            if (token != "#") {
                curr->left = new TreeNode(stoi(token));
                q.push(curr->left);
            } else {
                curr->left = NULL;
            }
            
            getline(ss, token, ',');
            if (token != "#") {
                curr->right = new TreeNode(stoi(token));
                q.push(curr->right);
            } else {
                curr->right = NULL;
            }
        }
        
        return root;
    }
};
