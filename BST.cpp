#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int key){

    struct node* temp = new node();
    temp->data = key;
    temp->left = temp->right = NULL;

    return temp;
};

struct node* insert(struct node* root,int key){

    if(root == NULL) return newNode(key);

    if(key > root->data)
        root->right = insert(root->right,key);
    else if(key < root->data)
        root->left = insert(root->left,key);

    return root;
};

struct node* search(struct node* root,int key){

    if(root == NULL) return NULL;

    if(key < root->data)
        search(root->left,key);
    else if(key > root->data)
        search(root->right,key);
    else return root;
};

struct node* setRight(struct node* root,struct node* temp){

    if(root == NULL){
        root = temp;
        return root;
    }
    setRight(root->right,temp);

}

struct node* delet(struct node* root,int key){

    if(root->data == key){
        struct node* temp = root->right;
        root = root->left;
        cout<<"data:    "<<root->data<<endl;
        if(root != NULL)
            setRight(root,temp);
        else root = temp;
        return root;
    }
    else if(root->data > key)
        root->left = delet(root->left,key);
    else if(root->data < key)
        root->right = delet(root->right,key);

}

void inorder(struct node* root){

    if(root == NULL) return;
    cout<<root->data<<" ";
    inorder(root->left);

    inorder(root->right);
}

int main(){

    int arr[] = {3,5,23,7,5,3,8,5};

    struct node *root = NULL;

    root = insert(root,arr[0]);

    for(int i = 0;i < 8; i++)
        insert(root,arr[i]);

    inorder(root);

    cout<<endl;

    struct node* value = search(root,28);

    if(value != NULL)
        cout<<value->data<<endl;

    else cout<<"Not in the list"<<endl;

    delet(root,5);

    inorder(root);

    return 0;
}
