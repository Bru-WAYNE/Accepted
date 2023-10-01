#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};
struct Node *head;
void createCLL(int data)
{
    struct Node *newNode=new Node(data);
    struct Node *temp;
    if(head==NULL)
    {
        head=newNode;
        temp=head;
    }
    else{
        temp->next=newNode;
        temp=temp->next;
    }
    temp->next=head;
}
void display()
{
    struct Node *temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
int main()
{
    createCLL(10);
    createCLL(20);
    createCLL(30);
    createCLL(40);
    display();
}
