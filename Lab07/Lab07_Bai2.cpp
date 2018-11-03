#include<iostream>
#include<fstream>

using namespace std;

void printArr(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

}

struct Node{
    int key;
    Node *left, *right;
    Node(int d){
        key = d;
        left = right = NULL;
    }
};

struct BST{
    Node *root;
    BST(){
        root = NULL;
    }
    void insertBST(Node* &r, int x){
        if(r == NULL)
            r = new Node(x);
        if(x > r->key)
            insertBST(r->right,x);
        if(x < r->key)
            insertBST(r->left,x);
    }

    void inOrder(Node *v){
        if(v != NULL){
            inOrder(v->left);
            cout << (v->key) << " ";
            inOrder(v->right);
        }
    }
    bool searchBST(Node* root, int x){
        if(root == NULL){
            return false;
        }
        else if(root->key == x){
                return true;
        }
        else if(x > root->key){
            searchBST(root->right,x);
        }
        else if(x < root->key){
            searchBST(root->left,x);
        }
    }

    int findMin(Node* &r){
        if(r->left == NULL){
            int p = r->key;
            r = r->right;
            return p;
        }
        else findMin(r->left);
    }

    void deleteBST(Node* &r, int x){
        if(x > r->key)
            deleteBST(r->right,x);
        else if(x < r->key)
            deleteBST(r->left,x);
        else {
            if(r->right == NULL)
                r = r->left;
            else if(r->left == NULL)
                r = r->right;
            else
                r->key = findMin(r->right);
        }
    }
};



int main(){
    ifstream input("Array.txt");
    if(input.fail())
        cout << "Failed to open this file!" << endl;

    int k, n = 0;
    int x = 9;
    int a[100];
    while(!input.eof()){
        input >> k;
        a[n++] = k;
    }

    BST* tree = new BST();
    for(int i = 0; i < n; i++){
        tree->insertBST(tree->root,a[i]);
    }
    tree->inOrder(tree->root);

    if(tree->searchBST(tree->root,x)){
        cout << endl << x <<" co ton tai trong cay." << endl;
    }
    else
        cout <<endl << x << " khong ton tai trong cay."<<endl;
    tree->deleteBST(tree->root,12);
    tree->inOrder(tree->root);

    return 0;
}
