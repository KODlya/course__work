#define size 10
#include <iostream>

using namespace std;
template<typename T>
class Node {
public:
    Node() { //Конструктор по умолчанию
        next = nullptr; prev = nullptr; ar_sz = 0;
        for (int i = 0; i < size; i++) {
            data[i] = nullptr;
        }
    }
    ~Node() {
        int i = 0;
        while (data[i] != nullptr) {
            delete data[i];
            i++;
        }
    }

    void NodePrint() {
        for (int i = 0; data[i] != nullptr; i++)
            cout << *(data[i]) << " ";
    }
    Node* next;
    Node* prev;
    T* data[size + 1];
    int ar_sz;
};
