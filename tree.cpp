#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node * right;
    node(int d){
        data=d;
        left= NULL;
        right=NULL;
    }
};

node* buildtree(int n[], int& i){
    if( n[i]==-1)
        return NULL;
    node* newNode= new node(n[i]);
    i++;
    newNode->left= buildtree(n, i);
    i++;
    newNode->right=buildtree(n, i);

    return newNode;
}

void preorder(node* root){

    if(root==NULL){
        cout<<-1;
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root){
    if(root==NULL){
        cout<<" ";
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void levelorder(node* root){
    if(root==NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* curr= q.back();
        q.pop();
        if(curr==NULL){
            cout<<endl;
            if(q.empty()){
                break;
            }
            else{
                q.push(NULL);  
            }
        }
        else{
            cout<<curr->data<<" ";
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }




}

int main(){

    int n[]={1,2,3,-1,-1,4,-1,-1,8,9,-1,-1,-1};
    int i=0;
    node* root=buildtree(n,i);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    levelorder(root);
    return 0;
}