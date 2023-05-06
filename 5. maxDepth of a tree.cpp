#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int data) {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

Node *buildTree() {
  int data;
  cout << "Enter the data: " << endl;
  cin >> data;

  if (data == -1) {
    return NULL;
  }

  Node *root = new Node(data);

  cout << "Enter the data on left part of " << data << endl;
  root->left = buildTree();

  cout << "Enter the data on right part of " << data << endl;
  root->right = buildTree();

  return root;
}

int maxDepth(Node *root) {
  if (root == NULL) {
    return 0;
  }

  int left = maxDepth(root->left);
  int right = maxDepth(root->right);
  int ans = max(left, right) + 1;
  return ans;
}

void levelOrderTraversal(Node *root) {
  queue<Node *> q;

  // initially
  q.push(root);

  while (!q.empty()) {
    // step 1:
    Node *temp = q.front();

    // step 2:
    q.pop();

    // step 3:
    cout << temp->data << " ";

    if (temp->left) {
      q.push(temp->left);
    }

    if (temp->right) {
      q.push(temp->right);
    }
  }
}

int main() {
  Node *root = NULL;
  root = buildTree();
  levelOrderTraversal(root);
  cout << endl;
  cout << "maximum depth of tree is: " << maxDepth(root);

  return 0;
}
