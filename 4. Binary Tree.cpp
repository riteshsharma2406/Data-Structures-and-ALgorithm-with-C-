//build a tree and level order traversal of tree
#include <iostream>
#include <queue>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

//creation of tree
Node *buildTree()
{
  int data;
  cout<<"Enter the data: "<<endl;
  cin>>data;

  //base case
  if(data==-1)
  {
    return NULL;
  }

  //step A , B, and C
  //step A:
  Node *root = new Node(data);

  //step B:
  cout<<"Enter data for left part of "<<data<<"node"<<endl;
  root->left = buildTree();

  //step C:
  cout<<"Enter data for right part of "<<data<<"node"<<endl;
  root->right = buildTree();

  return root;
}

//to level order traversal
void levelOrderTraversal(Node *root)
{
  queue<Node*> q;

  //initially
  q.push(root);
  q.push(NULL);
  while(!q.empty())
    {
      //step 1:
      Node *temp = q.front();

      //step 2:
      q.pop();

      if(temp==NULL)
      {
        cout<<endl;
        if(!q.empty())
        {
          q.push(NULL);
        }
      }
      else{
        //step 3:
        cout<<temp->data<<" ";
  
        //step 4:
        if(temp->left)
        {
          q.push(temp->left);
        }
  
        if(temp->right)
        {
          q.push(temp->right);
        }
      }
    }
}


//inorder traversal
void inorderTraversal(Node* root)
{
  //base case
  if(root==NULL)
  {
    return;
  }

  //LNR
  inorderTraversal(root->left);
  cout<<root->data<<" ";
  inorderTraversal(root->right);
}

//preorder Traversal
void preorderTraversal(Node *root)
{
    //base case
  if(root==NULL)
  {
    return;
  }

  //LNR
  cout<<root->data<<" ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}


//Post order traversal
void postorderTraversal(Node* root)
{
    //base case
  if(root==NULL)
  {
    return;
  }

  //LNR
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout<<root->data<<" ";
}


//maximum depth or height of a tree
int height(Node* root)
{
  //base case
  if(root==NULL)
  {
    return 0;
  }

  int leftHeight = height(root->left);
  int rightHeight = height(root->right);
  int ans = max(leftHeight,rightHeight) +1;
  return ans;
  
}

int main() {
  
  Node *root = NULL;
  root = buildTree();
  levelOrderTraversal(root);

  // inorderTraversal(root);

  // preorderTraversal(root);

  // postorderTraversal(root);

  cout<<"Height"<<height(root)<<endl;

  

  return 0;
}
