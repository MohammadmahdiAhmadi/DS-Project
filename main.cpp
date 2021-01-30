#include <iostream>
using namespace std;

#define OC 24 //OutputCapacity
#define SA 2  //SpeedOfArmy

//#include "StartGame.h"
#include "FibonacciHeap.h"


int main()
{
    FibonacciHeap fh;
    // We will create a heap and insert 3 nodes into it
    cout << "Creating an initial heap" << endl;
    fh.insertion(5);
    fh.insertion(2);
    fh.insertion(8);


    // Now we will display the root list of the heap
    fh.display();

    // Now we will extract the minimum value node from the heap
    cout << "Extracting min" << endl;
    fh.Extract_min();
    fh.display();

    // Now we will decrease the value of node '8' to '7'
    cout << "Decrease value of 8 to 7" << endl;
    fh.CFind(8, 7);
    fh.display();

    // Now we will delete the node '7'
    cout << "Delete the node 7" << endl;
    fh.Deletion(7);
    fh.display();



    return 0;
}



