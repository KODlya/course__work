#define size 10

template<typename T>
class Node {
public:
    Node() { //Конструктор по умолчанию
        next = nullptr; prev = nullptr; ar_sz = 0;
        for (int i = 0; i < size; i++) {
            data[i] = nullptr;
        }
    }
    Node* next;
    Node* prev;
    T* data[size + 1];
    int ar_sz;
};
