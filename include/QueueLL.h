#ifndef QUEUELL_H
#define QUEUELL_H


#include <iostream>
using namespace std;


template<class T>
class mynode
{
template<class G>
friend class QueueLL;

private:
    T data;
    mynode<T>* link;

};

template<class G>
class QueueLL
{
private:
    mynode<G>* Tail;
    long int noTerms;

public:
    QueueLL(){
        Tail = new mynode<G>();
        Tail->link = Tail;

        noTerms = 0;
    }
    ~QueueLL(){
        //destroying all nodes...
    }

    bool isEmpty() const;

    G head() const;

    G tail() const;

    void push(const G& term);

    void pop();

    long int NOTerms();

    mynode<G>* searchTerm(const G& term);

    void print();

};

template<class G>
bool QueueLL<G>::isEmpty() const{
    if(noTerms == 0)
        return true;
    return false;
}

template<class G>
G QueueLL<G>::head() const{
    if(isEmpty()) throw "Queue is empty";
    return Tail->link->data;
}

template<class G>
G QueueLL<G>::tail() const{
    if(isEmpty()) throw "Queue is empty";
    return Tail->data;
}

template<class G>
void QueueLL<G>::push(const G& term){
    if(noTerms == 0){
        Tail->data = term;
    }
    else{
        mynode<G>* newNode = new mynode<G>();
        newNode->data = term;
        newNode->link = Tail->link;
        Tail->link = newNode;
        Tail = newNode;
    }
    noTerms ++;
}

template<class G>
void QueueLL<G>::pop(){
    if(isEmpty()){
        cout << "Queue is empty. Cannot delete." << endl;
        return;
    }

    mynode<G>* tempNode = new mynode<G>();

    tempNode = Tail->link;
    Tail->link = tempNode->link;
    noTerms--;

    delete[] tempNode;
    return;
}

template<class G>
long int QueueLL<G>::NOTerms(){
    return noTerms;
}

template<class G>
mynode<G>* QueueLL<G>::searchTerm(const G& term){
    if(isEmpty())throw "Queue is empty";

    mynode<G>* i = new mynode<G>();
    int j = 0;
    for(i = Tail->link; i != Tail; i = i->link){
        if(i->data == term){
            cout << "Found '" << term << "' in index: " << j << endl;
            return i;
        }
        j++;
    }
    if(Tail->data == term){
        cout << "Found '" << term << "' in index: " << noTerms-1 << endl;
        return Tail;
    }
    delete[] i;


    cout << "Not found '" << term << "'" << endl;
    return NULL;
}

template<class G>
void QueueLL<G>::print(){
    if(isEmpty()){
        cout << "Queue is empty" << endl;
        return;
    }
    mynode<G>* i = new mynode<G>();
    for(i = Tail->link; i != Tail; i = i->link){
        cout << i->data << "  ";
    }
    cout << Tail->data << endl;

    delete[] i;
    return;
}

#endif // QUEUELL_H
