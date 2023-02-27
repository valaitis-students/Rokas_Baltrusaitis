#include "prioqueue.h"
int main()
{
    Node* kazkas = Create();
    Insert(kazkas, 10,10);
    Insert(kazkas, 5,20);
    Insert(kazkas, 5,100);
    Insert(kazkas, 7,15);
    Insert(kazkas, 20,30);
    Node* kazkas2 = Create();
    Insert(kazkas2, 1,1);
    Insert(kazkas2, 2,2);
    Insert(kazkas2,15,15);
    Insert(kazkas2,6,6);
    Join(kazkas, &kazkas2);
    print(kazkas2);
    print(kazkas);

    return 0;
}
