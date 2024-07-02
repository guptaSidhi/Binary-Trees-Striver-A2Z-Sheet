class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map <Node*,Node*> mp;
        mp[root] = NULL;
        queue <Node*> q;
        q.push(root);
        Node* final = NULL;
        while(!q.empty())
        {
            Node* temp = q.front();
            if(temp -> data == target) final = temp;
            q.pop();
            
            if(temp -> left)
            {
                q.push(temp -> left);
                mp[temp -> left] = temp;
            }
            
            if(temp -> right)
            {
                q.push(temp -> right);
                mp[temp -> right] = temp;
            }
        }
        
        unordered_set <Node*> vis;
        vis.insert(final);
        int time = 0;
        q.push(final);
        bool insert = false;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                Node* temp = q.front();
                q.pop();
                
                if(temp -> left && vis.find(temp->left) == vis.end())
                {
                    insert = true;
                    q.push(temp -> left);
                    vis.insert(temp -> left);
                }
                
                if(temp -> right && vis.find(temp->right) == vis.end())
                {
                    insert = true;
                    q.push(temp -> right);
                    vis.insert(temp -> right);
                }
                
                if(mp[temp] && vis.find(mp[temp]) == vis.end())
                {
                    insert = true;
                    q.push(mp[temp]);
                    vis.insert(mp[temp]);
                }
            }
            
            if(insert == true) time++;
            insert = !insert;
        }
        
        return time;
    }
};