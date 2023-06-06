class Solution{
  public:
    void inorder(vector<int>&ans, Node* root)
    {
        if(root==NULL)
        {
            return;
        }
        
        inorder(ans,root->left);
        ans.push_back(root->data);
        inorder(ans,root->right);
        
    }
    
    void postOrder(vector<int>&ans, Node*root , int &index)
    {
        if(root==NULL)
        {
            return;
        }
        
        postOrder(ans,root->left,index);
        postOrder(ans,root->right,index);
        root->data = ans[index++];
        
    }
  
    void convertToMaxHeapUtil(Node* root)
    {
        // Your code goes here
        vector<int>ans;
        inorder(ans,root);
        int index = 0;
        postOrder(ans,root,index);
    }    
};
