//reverse the Kth node in the Linked List
#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node *next;

  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};

void print(Node* &head)
{
  Node *temp = head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp = temp -> next;
  }
}

int getLength(Node* &head)
{
  int len = 0;
  Node *temp = head;
  while(temp!=NULL)
  {
    temp = temp -> next;
    len++;
  }
  return len;
}

Node *reverseKNodes(Node* &head, int k)
{
  if(head==NULL || head->next==NULL)
  {
    return head;
  }
  int len = getLength(head);
  if(k>len)
  {
    return head;
  }

  //step 1: reverse first K-th node of LL
  Node *prev = NULL;
  Node *curr = head;
  Node *forward = NULL;
  int count = 0;

  while(count<k)
  {
    forward = curr->next;
    curr -> next = prev;
    prev = curr;
    curr = forward;
    count++;
  }

  //step2 : reverse the rest LL
  if(forward!=NULL)
  {
    //we still have nodes to reverse
    head->next = reverseKNodes(forward,k);
  }

  //step 3: return head of modified LL
  return prev;

}

int main() {
  
  Node *head = new Node(10);
  Node *second = new Node(20);
  Node *third = new Node(30);
  Node *fourth = new Node(40);
  Node *fifth = new Node(50);
  Node *sixth = new Node(60);

  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;

  print(head);
  cout<<endl;
  head = reverseKNodes(head,1);
  print(head);


  return 0;
}
