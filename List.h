#include "Node.h"

template<typename T>
class List {
public:
    List();
    ~List();
    bool IsEmpty();
    void Add2(T& n);
    Node<T>* Search(int& pos);
    T* operator[](int pos);
    void FreeMemory();
    void ListPrint();
    void ListPrintBack();
    void InsertPos(T* n, int pos);
    void Sort();
    Node<T>* MinSize();
    Node<T>* MaxSize();
    void Balance();
    void InSort(T* n);
    Node<T>* Min(Node<T>* p, int& pos);
    T* Delete(int pos);
    void SaveToBin(ofstream& f);
    void LoadFromBin(ifstream& f);
private:
    Node<T>* head;
    int list_sz;
};
