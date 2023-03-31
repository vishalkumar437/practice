#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int d){
        this->data=d;
        this->next=NULL;
    }
};
class queue{
    public:
    node* front;
    node* rear;
    queue(){
        rear=NULL;
        front=NULL;
    }
    
    void insert(int data){
        node* newNode=new node(data);
        if(rear==NULL){
            rear=newNode;
            front=newNode;
            return;
    }
        rear->next = newNode;
        rear=newNode;

}
    void dequeue(){
        node* temp=NULL;
        if(front==NULL){
            cout<<"underflow";
            return;
        }
        temp=front;
        front=front->next;
        free(temp);
    }
    
void peek(){
    cout<<front->data<<endl;
    cout<<rear->data<<endl;
}
};

int main(){

    queue q;
    q.insert(4);
    q.insert(45);
    q.insert(87);
    q.peek();
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
    cout<<"\n";
    q.dequeue();
    q.peek();
    return 0;
}