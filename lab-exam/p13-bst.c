// insert , display in ascending order(inorder) , find highest and lowest , search 

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * right;
    struct Node * left;
};

struct Node * root = NULL;

struct Node * insertToBST(int item, struct Node * root){
    struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL){
        root = temp;
        return root;
    }
    struct Node * cur = root;
    struct Node * prev = NULL;
    while(cur!=NULL){
        prev = cur;
        if(item < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    if(item < prev->data) prev->left = temp;
    else prev->right = temp;
    return root;
}

//to display in ascending order

void inorder(struct Node * root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct Node * root){
    if(root == NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node * root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

void findLargest(struct Node * root){
    if(root == NULL) printf("empty bst");
    else{
        struct Node * cur = root;
        struct Node * temp = NULL;
        while(cur!=NULL){
            temp = cur;
            cur = cur->right;
        }

        printf("Largest entry in BST = %d\n",temp->data);
    }
}

void findSmallest(struct Node * root){
    if(root == NULL) printf("empty bst");
    else{
        struct Node * cur = root;
        struct Node * temp = NULL;
        while(cur!=NULL){
            temp = cur;
            cur = cur->left;
        }

        printf("Smallest entry in BST = %d\n",temp->data);
    }
}

void searchItem(struct Node * root, int item){
    if(root == NULL){
        printf("empty bst");
        return;
    }  
    struct Node * cur = root;
    while(cur!=NULL){
        if(cur->data == item){
            printf("%d found\n",item);
            return;
        }
        else if(item < cur->data){
            cur = cur->left;
        }
        else{
            cur = cur->right;
        }
    }
    printf("%d not found\n",item);
    
}

void main(){
    root = insertToBST(100,root);
    root = insertToBST(50,root);
    root = insertToBST(110,root);
    root = insertToBST(200,root);
    root = insertToBST(10,root);
    root = insertToBST(170,root);
    root = insertToBST(70,root);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    findLargest(root);
    findSmallest(root);
    searchItem(root,60);
    searchItem(root,70);
}