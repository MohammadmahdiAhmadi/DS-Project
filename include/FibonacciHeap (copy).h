#ifndef FIBONACCIHEAP_H
#define FIBONACCIHEAP_H


    #include <iostream>
    #include <cmath>
    #include <cstdlib>

    using namespace std;
    /*
     * Node Declaration
    */

    class myNode
    {
        public:
        int n;
        int degree;
        myNode* parent;
        myNode* child;
        myNode* left;
        myNode* right;
        char mark;
        char C;

    };

    /*

     * Class Declaration

     */

    class FibonacciHeap
    {
        private:
            int nH;
            myNode *H;
        public:
            myNode* InitializeHeap();
            int Fibonnaci_link(myNode*, myNode*, myNode*);
            myNode *Create_node(int);
            myNode *Insert(myNode *, myNode *);
            myNode *Union(myNode *, myNode *);
            myNode *Extract_Min(myNode *);
            int Consolidate(myNode *);
            int Display(myNode *);

            myNode *Find(myNode *, int);
            int Decrease_key(myNode *, int, int);
            int Delete_key(myNode *,int);
            int Cut(myNode *, myNode *, myNode *);
            int Cascase_cut(myNode *, myNode *);
            FibonacciHeap()
            {
                H = InitializeHeap();
            }
    };

    /*
     * Initialize Heap
    */

    myNode* FibonacciHeap::InitializeHeap()
    {
        myNode* np;
        np = NULL;
        return np;
    }

    /*

     * Create Node

     */

    myNode* FibonacciHeap::Create_node(int value)
    {
        myNode* x = new myNode;
        x->n = value;
        return x;
    }

    /*

     * Insert Node

     */

    myNode* FibonacciHeap::Insert(myNode* H, myNode* x)
    {
        x->degree = 0;
        x->parent = NULL;
        x->child = NULL;
        x->left = x;
        x->right = x;
        x->mark = 'F';
        x->C = 'N';
        if (H != NULL)
        {
            (H->left)->right = x;
            x->right = H;
            x->left = H->left;
            H->left = x;
            if (x->n < H->n)
                H = x;
        }
        else
        {
            H = x;
        }

        nH = nH + 1;
        return H;
    }

    /*

     * Link Nodes in Fibonnaci Heap

     */

    int FibonacciHeap::Fibonnaci_link(myNode* H1, myNode* y, myNode* z)
    {
        (y->left)->right = y->right;
        (y->right)->left = y->left;
        if (z->right == z)
            H1 = z;

        y->left = y;
        y->right = y;
        y->parent = z;

        if (z->child == NULL)
            z->child = y;

        y->right = z->child;
        y->left = (z->child)->left;
        ((z->child)->left)->right = y;
        (z->child)->left = y;

        if (y->n < (z->child)->n)
            z->child = y;

        z->degree++;
    }

    /*

     * Union Nodes in Fibonnaci Heap

     */

    myNode* FibonacciHeap::Union(myNode* H1, myNode* H2)
    {
        myNode* np;
        myNode* H = InitializeHeap();
        H = H1;
        (H->left)->right = H2;
        (H2->left)->right = H;
        np = H->left;
        H->left = H2->left;
        H2->left = np;
        return H;
    }

    /*

     * Display Fibonnaci Heap

     */

    int FibonacciHeap::Display(myNode* H)
    {
        myNode* p = H;
        if (p == NULL)
        {
            cout<<"The Heap is Empty"<<endl;
            return 0;
        }

        cout<<"The root nodes of Heap are: "<<endl;
        do
        {
            cout<<p->n;
            p = p->right;
            if (p != H)
            {
                cout<<"-->";
            }
        }
        while (p != H && p->right != NULL);

        cout<<endl;
    }

    /*

     * Extract Min Node in Fibonnaci Heap

     */

    myNode* FibonacciHeap::Extract_Min(myNode* H1)
    {
        myNode* p;
        myNode* ptr;
        myNode* z = H1;
        p = z;
        ptr = z;

        if (z == NULL)
            return z;

        myNode* x;
        myNode* np;
        x = NULL;
        if (z->child != NULL)
            x = z->child;

        if (x != NULL)
        {
            ptr = x;
            do
            {
                np = x->right;
                (H1->left)->right = x;
                x->right = H1;
                x->left = H1->left;
                H1->left = x;
                if (x->n < H1->n)
                    H1 = x;

                x->parent = NULL;
                x = np;
            }
            while (np != ptr);

        }
        (z->left)->right = z->right;
        (z->right)->left = z->left;
        H1 = z->right;
        if (z == z->right && z->child == NULL)
            H = NULL;
        else
        {
            H1 = z->right;
            Consolidate(H1);
        }

        nH = nH - 1;
        return p;
    }

    /*

     * Consolidate Node in Fibonnaci Heap

     */

    int FibonacciHeap::Consolidate(myNode* H1)
    {
        int d, i;
        float f = (log(nH)) / (log(2));
        int D = f;
        myNode* A[D];
        for (i = 0; i <= D; i++)
            A[i] = NULL;

        myNode* x = H1;
        myNode* y;
        myNode* np;
        myNode* pt = x;

        do
        {
            pt = pt->right;
            d = x->degree;
            while (A[d] != NULL)
            {
                y = A[d];
                if (x->n > y->n)
                {
                    np = x;
                    x = y;
                    y = np;

                if (y == H1)
                    H1 = x;

                Fibonnaci_link(H1, y, x);

                if (x->right == x)
                    H1 = x;

                    A[d] = NULL;
                d = d + 1;

            }
            A[d] = x;
            x = x->right;

        }
        }
        while (x != H1);

        H = NULL;
        for (int j = 0; j <= D; j++)
        {
            if (A[j] != NULL)
            {
                A[j]->left = A[j];
                A[j]->right =A[j];
                if (H != NULL)
                {
                    (H->left)->right = A[j];
                    A[j]->right = H;
                    A[j]->left = H->left;
                    H->left = A[j];
                    if (A[j]->n < H->n)
                    H = A[j];
                }
                else
                {
                    H = A[j];
                }

                if(H == NULL)
                    H = A[j];

                else if (A[j]->n < H->n)
                    H = A[j];
            }
        }
    }



    /*

     * Decrease key of myNodes in Fibonnaci Heap

     */

    int FibonacciHeap::Decrease_key(myNode*H1, int x, int k)
    {
        myNode* y;
        if (H1 == NULL)
        {
            cout<<"The Heap is Empty"<<endl;
            return 0;
        }
        myNode* ptr = Find(H1, x);
        if (ptr == NULL)
        {
            cout<<"Node not found in the Heap"<<endl;
            return 1;
        }
        if (ptr->n < k)
        {
            cout<<"Entered key greater than current key"<<endl;
            return 0;
        }

        ptr->n = k;
        y = ptr->parent;
        if (y != NULL && ptr->n < y->n)
        {
            Cut(H1, ptr, y);
            Cascase_cut(H1, y);
        }

        if (ptr->n < H->n)
            H = ptr;

        return 0;

    }

    /*

     * Cut Nodes in Fibonnaci Heap

     */

    int FibonacciHeap::Cut(myNode* H1, myNode* x, myNode* y)
    {
        if (x == x->right)
            y->child = NULL;

        (x->left)->right = x->right;
        (x->right)->left = x->left;
        if (x == y->child)
            y->child = x->right;

        y->degree = y->degree - 1;
        x->right = x;
        x->left = x;
        (H1->left)->right = x;
        x->right = H1;
        x->left = H1->left;
        H1->left = x;
        x->parent = NULL;
        x->mark = 'F';

    }



    /*

     * Cascade Cutting in Fibonnaci Heap

     */

    int FibonacciHeap::Cascase_cut(myNode* H1, myNode* y)
    {
        myNode* z = y->parent;
        if (z != NULL)
        {
            if (y->mark == 'F')
            {
                y->mark = 'T';
    	}
            else
            {
                Cut(H1, y, z);
                Cascase_cut(H1, z);
            }
        }
    }

    /*
     * Find Nodes in Fibonnaci Heap
    */

    myNode* FibonacciHeap::Find(myNode* H, int k)
    {
        myNode* x = H;
        x->C = 'Y';
        myNode* p = NULL;
        if (x->n == k)
        {
            p = x;
            x->C = 'N';
            return p;
        }
        if (p == NULL)
        {
            if (x->child != NULL )
                p = Find(x->child, k);

            if ((x->right)->C != 'Y' )
                p = Find(x->right, k);
        }
        x->C = 'N';

        return p;
    }

    /*
     * Delete Nodes in Fibonnaci Heap
    */

    int FibonacciHeap::Delete_key(myNode* H1, int k)
    {
        myNode* np = NULL;
        int t;
        t = Decrease_key(H1, k, -5000);

        if (!t)
            np = Extract_Min(H);

        if (np != NULL)
            cout<<"Key Deleted"<<endl;

        else
            cout<<"Key not Deleted"<<endl;

        return 0;
    }

    /*

     * Main Contains Menu

     */
/*
    int main()

    {

        int n, m, l;

        FibonacciHeap fh;

        myNode* p;

        myNode* H;

        H = fh.InitializeHeap();

        while (1)

        {

            cout<<"----------------------------"<<endl;

            cout<<"Operations on Binomial heap"<<endl;

            cout<<"----------------------------"<<endl;

            cout<<"1)Insert Element in the heap"<<endl;

            cout<<"2)Extract Minimum key node"<<endl;

            cout<<"3)Decrease key of a node"<<endl;

            cout<<"4)Delete a node"<<endl;

            cout<<"5)Display Heap"<<endl;

            cout<<"6)Exit"<<endl;

            cout<<"Enter Your Choice: ";

            cin>>l;

            switch(l)

            {

            case 1:

                cout<<"Enter the element to be inserted: ";

                cin>>m;

                p = fh.Create_node(m);

                H = fh.Insert(H, p);

                break;

            case 2:

                p = fh.Extract_Min(H);

                if (p != NULL)

                    cout<<"The node with minimum key: "<<p->n<<endl;

                else

                    cout<<"Heap is empty"<<endl;

                break;

            case 3:

                cout<<"Enter the key to be decreased: ";

                cin>>m;

                cout<<"Enter new key value: ";

                cin>>l;

                fh.Decrease_key(H, m, l);

                break;

            case 4:

                cout<<"Enter the key to be deleted: ";

                cin>>m;

                fh.Delete_key(H, m);

                break;

            case 5:

                cout<<"The Heap is: "<<endl;

                fh.Display(H);

                break;

            case 6:

                exit(1);

            default:

                cout<<"Wrong Choice"<<endl;

            }

        }

        return 0;

    }
*/
#endif // FIBONACCIHEAP_H
