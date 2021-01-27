#ifndef AVL_H
#define AVL_H

#include<bits/stdc++.h>
using namespace std;

#include "StackLL.h"

class Node{

friend class Avl;

private:
    int key;
    Node* left;
    Node* right;

public:
    int height;

    Node(int data = 0){
        this->key = data;
        this->left = NULL;
        this->right = NULL;
    }

};


class Avl
{
    public:
        Avl();
        virtual ~Avl();

        void add(int key);
        void del(int key);
        void pre();
        StackLL<int> reverseLevelOrder();


    private:
        Node* root;


        Node* newNode(int key);
        Node* rightRotate(Node *y);
        Node* leftRotate(Node *x);
        int getBalance(Node *N);
        Node* insert(Node* node, int key);

        Node* minValueNode(Node* node);
        Node* deleteNode(Node* root, int key);

        void preOrder(Node *root);

};

#endif // AVL_H
