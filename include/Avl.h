#ifndef AVL_H
#define AVL_H

#include<bits/stdc++.h>
using namespace std;

#include "StackLL.h"

class Node{

friend class Avl;

private:

    Node* left;
    Node* right;

public:
    int key;
    int height;
    int CastleId;//EXTRA

    Node(int data = 0, int castleId=-1){
        this->key = data;
        this->CastleId = castleId;//Extra
        this->left = NULL;
        this->right = NULL;
    }

};


class Avl
{
    public:
        Avl();
        virtual ~Avl();

        void add(int key, int castleId=-1);//EXTRA
        void del(int key, int castleId=-1);//EXTRA
        void pre();
        void in();
        vector<Node*> inVector;
        StackLL<int> reverseLevelOrder();


    private:
        Node* root;


        Node* newNode(int key, int castleId);//EXTRA
        Node* rightRotate(Node *y);
        Node* leftRotate(Node *x);
        int getBalance(Node *N);
        Node* insert(Node* node, int key, int castleId);//EXTRA

        Node* minValueNode(Node* node);
        Node* deleteNode(Node* root, int key, int castleId=-1);//EXTRA

        void preOrder(Node *root);
        void inOrder(Node *root);


};

#endif // AVL_H
