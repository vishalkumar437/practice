#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;

};

node* create(int data){
        node* newNode=new node;
        newNode->data=data;
        newNode->left=NULL;
        newNode->right=NULL;

        return newNode;
    }


node* insertion(node* root,int data){

        if(root==NULL){
            return create(data);
        }
        if(root->data>data)
            root->left=insertion(root->left,data);
        if(root->data<data)
            root->right=insertion(root->right,data);

        return root;
}
    
void inorder(node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
}

void search(node* &cur,int data,node* &parent){
            while(cur!=NULL&& cur->data!=data){
                    parent=cur;
                if(cur->data>data)
                    cur=cur->left;
                else{
                    cur=cur->right;
                }
            }
}

node* findMinimum(node* root){
            while(root->left!=NULL){
                root=root->left;

            }
            return root;

}

void deletion(node* root,int data){

        node* parent =NULL;
        node* cur=root;
        search(cur,data,parent);
        if(cur==NULL){
            return;
        }
        if(cur->left == NULL && cur->right == NULL){
            if(cur != NULL){
                if(parent->left == cur){
                    parent->left = NULL;
                }
                else{
                    parent->right = NULL;
                }
            }

            else{
                root = NULL;
                free(cur);
            }
        }

        else if(cur->left && cur->right){
            node* succ = findMinimum(root->right);
            int val = succ->data;
            deletion(root,succ->data);
            cur->data = val;
        }

        else{

            node* child = (cur->left)? cur->left : cur->right;
            if(cur!=root){
                if(cur==parent->left)
                    parent->left=child;
                else
                    parent->right=child;
            }
            else{
                root=child;
                free(cur);
            }
        }

}

int height(node* root){

    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);

    if(left>right)
        return left+1;
    else
        return right+1;
}
void printCurrlevel(node* root,int l){
    if(root==NULL){
        return;
    }
    if(l==1){
        cout<<root->data<<"\t";
    }
    else if(l>1){
        printCurrlevel(root->left,l-1);
        printCurrlevel(root->right,l-1);
    }
}

void levelorder(node* root){

    int h=height(root);
    int i;
    for(i=1;i<=h;i++)
        printCurrlevel(root,i);

}



int main(){


    node* root = NULL;
    root = insertion(root, 45);  
    root = insertion(root, 30);  
    root = insertion(root, 50);  
    root = insertion(root, 25);  
    root = insertion(root, 35);  
    root = insertion(root, 45);  
    root = insertion(root, 60);  
    root = insertion(root, 4);  
    printf("The inorder traversal of the given binary tree is - \n");  
    inorder(root);  
    deletion(root, 25);  
    printf("\nAfter deleting node 25, the inorder traversal of the given binary tree is - \n");  
    inorder(root);   
    insertion(root, 2);  
    printf("\nAfter inserting node 2, the inorder traversal of the given binary tree is - \n");  
    inorder(root);  
    cout<<"\n Level Order \n";
    levelorder(root);
    return 0;  



    return 0;
}