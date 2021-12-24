#include "Node.h"

template<typename T>
class List {
public:
    List();
    void Add(T& n);
    void ListPrint();
    void ListPrintBack();
    bool IsEmpty();
    T* Delete(int pos);
private:
    Node<T>* head;
    int list_sz;
};
