#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
   T data;
   Node *next;

   Node(T value)
   {
      data = value;
      next = NULL;
   }
};

template <typename T>
class LinkedList
{
private:
   Node<T> *head = NULL;

public:
   LinkedList()
   {
      head = NULL;
   } // default constructor
   void createList(T array[], int size);
   void InsertAt(T value, int position);
   void display();
};
template <typename T>
void LinkedList<T>::createList(T array[], int size)
{
   head = new Node<T>(array[0]);
   Node<T> *last = head;
   Node<T> *current = NULL;
   for (int i = 1; i < size; i++)
   {
      current = new Node<T>(array[i]);
      current->next = NULL;
      last->next = current;
      last = current;
   }
}
template <typename T>
void LinkedList<T>::display()
{
   Node<T> *temp = head;
   while (temp != NULL)
   {
      cout << temp->data << "->";
      temp = temp->next;
   }
   cout << "NULL\n";
}
template <typename T>
void LinkedList<T>::InsertAt(T value, int position)
{
   Node<T> *temp = head;
   Node<T> *last;
   int count=0;
   while(temp!=NULL){count++;temp=temp->next;last=temp;}//to count number of nodes.
  
   Node<T> *newNode = new Node<T>(value);
   if (position == 0)
   {
      head = newNode;
      newNode->next = temp;
   }
   else
   {
         Node<T> *temp2=head;
      for(int i=0;i<=position;i++){
         temp2=temp2->next;
      }
      Node<T> *temp3=temp2;
      temp2->next=newNode;
      newNode->next=temp3->next;
   }
}

int main()
{
   int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
   LinkedList<int> *list = new LinkedList<int>();
   list->createList(array, 10);
   list->display();

   list->InsertAt(9, 2);
   list->display();
}
