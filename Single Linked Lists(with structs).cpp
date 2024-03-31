#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node *next;
};
Node *head = new Node;

void InsertInMiddle(Node *newNode)
{
  if (head == NULL)
    head = newNode;
  else
  {
    Node *current = head;
    while (current->next != NULL)
    {
      if (current!= NULL && current->data <= newNode->data)
        current = current->next;
      current->next = current;
    }
    // because the current node data is still less than the new data.
    newNode->next = current->next; // So it'll be inserted in z middle of z current and node after it dumb ass dont forget!!.
    current->next = newNode;
  }
}
void InsertAtEnd(Node *newNode)
{ // we should check if list is empty or not 1st dumb dumb!!
  if (head == NULL)
    head = newNode;
  else
  {
    newNode->next = NULL;
    Node *temp = head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    temp = temp->next;
  }
}
void InsertAtBeginning(Node *newNode)
{
  if (head == NULL)
    head = newNode;
  else
  {
    newNode->next = head;
    head = newNode;
  }
}
void DeleteAtBeginning()
{
  Node *temp = head;
  if (head == NULL)
    cout << "List is Empty Dude!";
  else
  {
    head = head->next; // move head to the next node.
    cout << temp->data << " was deleted from your list.\n";
    delete temp;
  }
}
void DeleteAtEnd()
{
  Node *temp = head;
  if (head == NULL)
    cout << "List is Empty Dude!";
  else
  {
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp = temp->next;
    cout << temp->data << " was deleted from your list.\n";
    delete temp;
  }
}
void display(Node *temp)
{
  temp=head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}
int main()
{
  Node *n1 = new Node;

  head = n1;
  Node *t2; // because using head directly destroys the list.

  Node *n2 = new Node;
  Node *n3 = new Node;
  Node *n4 = new Node;
  Node *FirstNode = new Node; // Node to be inserted at begining.
  Node *LastNode = new Node;  // Node to be inserted at End.
  Node *MiddleNode = new Node;
  n1->data = 1;
  n1->next = n2;

  FirstNode->data = 0;
  InsertAtBeginning(FirstNode);

  LastNode->data = 6;
  MiddleNode->data = 5;

  n2->data = 2;
  n2->next = n3;

  n3->data = 3;
  n3->next = n4;

  n4->data = 4;
  n4->next = NULL;

  InsertAtEnd(LastNode);
  // DeleteAtBeginning();
  // DeleteAtEnd();
  //InsertInMiddle(MiddleNode);
  display(t2);
}