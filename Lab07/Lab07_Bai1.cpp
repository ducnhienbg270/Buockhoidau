#include<iostream>

using namespace std;

struct Node{
    char data;
    Node *left, *right;
    Node(char d){
        data = d;
        left = right = NULL;
    }
};

int searchIndex(char arr[], int Start, int End, char value){
    int i;
    for(i = Start; i <= End; i++){
        if(arr[i] == value)
            return i;
    }
}

Node* buildBinaryTree(char in[], char pre[], int inStart, int inEnd){
    int preIndex = 0;

    if(inStart > inEnd)
        return NULL;
    Node* tNode = new Node(pre[preIndex++]);

    if(inStart = inEnd)
        return tNode;
    int inIndex = searchIndex(in,inStart,inEnd,tNode->data);

    tNode->left = buildBinaryTree(in,pre,inStart,inIndex - 1);
    tNode->right = buildBinaryTree(in,pre,inIndex + 1,inEnd);
    return tNode;
}

    void inOrder(Node *v){
        if(v != NULL){
            inOrder(v->left);
            cout << (v->data) << " ";
            inOrder(v->right);
        }
    }

int main(){
    char pre[] = {'a','b','c','d','f','g','e'};
    char in[] = {'c','b','f','d','g','a','e'};
    int len = sizeof(in);
    Node *root = buildBinaryTree(in,pre,0,len-1);
    inOrder(root);
    return 0;
}
