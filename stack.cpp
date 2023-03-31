#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int d){
        this->data=d;
        this->next=NULL;
    }

};


class stack{
    public:
    node* top;
    stack(){
    top= NULL;
    }
void insert(int data){
    node* newNode=new node(data);
        if(!newNode){
            cout<<"Stack Overflow";
            exit(1);
        }
        
        newNode->next=top;
        top=newNode;
        

}

void peek(){
    cout<<top->data<<endl;
}
void pop(){
    node* temp;
    if(top==NULL){
        cout<<"Underflow";
        return;
    }
    temp=top;
    top=top->next;

    free(temp);



}
};

int main(){

    stack s;
    s.insert(1);
    s.insert(14);
    s.insert(534);
    s.pop();
    s.peek();
    s.pop();
    s.peek();
    s.pop();

    return 0;
}