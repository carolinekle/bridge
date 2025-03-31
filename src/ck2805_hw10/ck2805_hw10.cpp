#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <class T>
class LListNode{
    T data;
    LListNode<T>* next;
    public:
        LListNode (T newdata = T (), LListNode<T>* newNext = nullptr) : data (newdata), next (newNext) {}
        friend class LList <T> ;

};

int main (){

    return 0;
}