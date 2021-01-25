#ifndef STACKLL_H
#define STACKLL_H

#include <iostream>
using namespace std;

template<class T>
class node
{
template<class G>
friend class StackLL;

private:
    T data;
    node<T>* link;

};

template<class G>
class StackLL
{
private:
    node<G>* Top;
    long int noTerms;

public:
    StackLL(){
        Top = new node<G>();
        Top->link = NULL;

        noTerms = 0;
    }
    ~StackLL(){
        //destroying all nodes...
    }


    bool isEmpty() const;

    G top() const;

    void push(const G& term);

    void pop();

    long int NOTerms();

    node<G>* searchTerm(const G& term);

    void print();

};

template<class G>
bool StackLL<G>::isEmpty() const{
    if(noTerms == 0)
        return true;
    return false;
}

template<class G>
G StackLL<G>::top() const{
    if(isEmpty()) throw "stack is empty";
    return Top->data;
}

template<class G>
void StackLL<G>::push(const G& term){
    if(noTerms == 0){
        Top->data = term;
    }
    else{
        node<G>* newNode = new node<G>();
        newNode->data = term;
        newNode->link = Top;
        Top = newNode;
    }
    noTerms ++;
}

template<class G>
void StackLL<G>::pop(){
    if(isEmpty()){
        cout << "Stack is empty. Cannot delete." << endl;
        return;
    }

    node<G>* tempNode = new node<G>();
    tempNode = Top;

    Top = Top->link;
    noTerms--;

    delete[] tempNode;
    return;
}

template<class G>
long int StackLL<G>::NOTerms(){
    return noTerms;
}

template<class G>
node<G>* StackLL<G>::searchTerm(const G& term){
    if(isEmpty())throw "Stack is empty";

    node<G>* i = new node<G>();
    int j = noTerms - 1;
    for(i = Top; i != NULL; i = i->link){
        if(i->data == term){
            cout << "Found '" << term << "' in index: " << j << endl;
            return i;
        }
        j--;
    }
    delete[] i;

    cout << "Not found '" << term << "'" << endl;
    return NULL;
}

template<class G>
void StackLL<G>::print(){
    if(isEmpty()){
        cout << "Stack is empty" << endl;
        return;
    }
    node<G>* i = new node<G>();
    int j = noTerms - 1;
    for(i = Top; i != NULL; i = i->link){
        cout << j << ": " << i->data << endl;
        j--;
    }
    delete[] i;

    return;
}



#endif // STACKLL_H
