struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}

class Solution{
public:

    void create_tree(node* root0, vector<int> &vec){
        //Your code goes here
        int index = 1;
        queue <node*> q;
        q.push(root0);
        while(index < vec.size())
        {
            node* top = q.front();
            q.pop();
            if(vec[index] != -1)
            {
                top -> left = newNode(vec[index]);
                q.push(top -> left);
            }
            else top -> left = NULL;
            
            index++;
            
            if(index < vec.size() && vec[index] != -1)
            {
                top -> right = newNode(vec[index]); 
                q.push(top -> right);
            }
            else top -> right = NULL;
            
            index++;
        }
    }
};
