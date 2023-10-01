#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int d)
    {   data =d;
        next = NULL;
        prev = NULL;
    }
};
// ............................................................................
struct Node *head;
 struct Node *temp = head;
//  ..............................................................................
void createDL(int new_data)
{
    // struct Node *newNode = new Node();
    struct Node *newNode = new Node(new_data);
   
    // newNode->data = new_data;

    if (head == NULL)
    {
        head =temp= newNode;
    }
    else
    {
        newNode->prev = temp;
        temp->next = newNode;
        // temp = temp->next;
        temp=newNode;
    }
}
// ...................................................................................
void display()
{
    struct Node *temp1 = head;
    while (temp1 != NULL)
    {
        cout << temp1->data << endl;
        temp1 = temp1->next;
    }
}
// ....................................................................................
void reverseDLL()
{
    struct Node *current=head;
    struct Node *age_wala=current->next;
    if(head==NULL||head->next==NULL)
    {
        return;
    }
    else{
        while(current!=NULL)
        {
            // swap(current->next,current->prev);
            // current=current->prev;
            current->next=current->prev;
            current->prev=age_wala;
            current=age_wala;
            current=current->prev;
        }
    }
}
int main()
{
    createDL(5);
    createDL(10);
    createDL(15);
    // createDL(20);
    // createDL(55);
    display();
    reverseDLL();
    display();
}