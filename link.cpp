#include<iostream>
using namespace std;
class node{
    public:
int data;
node* next;
int data;
node(int d){
data=d;
}
};
void create(node *head,int data){
node *n=new node(data);
node *t=head;
if(head==NULL)
{
    head=n;
    return;
}
else{
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=n;
}
}
void display(node *head)
{
    node *t=head;
    while(t->next!=NULL)
    {
        cout<<t->data;
        cout<<"->";
        t=t->next;
    }
    cout<<t->next;
}
int main(){

    node *head=NULL;
    create(head,5);
    create(head,6);
    create(head,7);
return 0;
}
