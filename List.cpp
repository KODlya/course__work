#include <iostream>
#include <fstream>
#include "List.h"
#define N 0.8
using namespace std;

template<typename T>
List<T>::List() {
    head = nullptr;
    list_sz = 0;
}

template<typename T>
void List<T>::FreeMemory() {
    do {
        Delete(0);
    } while (head != nullptr);
}

template<typename T>
List<T>::~List() {
    FreeMemory();
}

template<typename T>
bool List<T>::IsEmpty() {
    return(head == nullptr);
}

template<typename T>
Node<T>* List<T>::Min(Node<T>* p, int& pos) {
    Node<T>* cur = p;
    Node<T>* min = p;
    int i;
    do {
        if (cur == p)  i = pos;
        else  i = 0;
        for (; i < cur->ar_sz; i++)
            if (*cur->data[i] < *min->data[pos]) {
                min = cur;
                pos = i;
            }
        cur = cur->next;
    } while (cur != head);
    return min;
}


template <typename T>
void List<T>::Sort() { // сортировка выбором
    Node<T>* cur = head;
    do {
        for (int i = 0, m; i < cur->ar_sz; i++) {
            m = i;
            Node<T>* k = Min(cur, m);
            T* c = k->data[m];  k->data[m] = cur->data[i]; cur->data[i] = c;
        }
        cur = cur->next;
    } while (cur != head);
}


template<typename T>
void List<T>::Add2(T& n) {//добавление в конец списка
    if (IsEmpty()) { //добавление заголовка
        head = new Node<T>();
        head->next = head;
        head->prev = head;
        head->data[0] = &n;
        head->data[1] = nullptr;
        head->ar_sz++;
        list_sz++;
    }
    else {
        Node<T>* cur = head;
        do {
            cur = cur->next;
        } while (cur != head);
        cur = cur->prev;
        if (cur->ar_sz < size)//если текущий массив указателей заполнен не полностью, добавляем в него новый элемент
        {
            cur->data[cur->ar_sz] = &n;
            cur->data[cur->ar_sz + 1] = nullptr;
            cur->ar_sz++;
        }
        else {// иначе - создаем новый элемент списка, записываем в его массив первый элемент
            Node<T>* temp, * p;
            int k = 0;
            temp = new Node<T>();
            temp->ar_sz = 0;
            p = head->prev;
            head->prev = temp;
            temp->prev = p;
            temp->next = head;
            p->next = temp;
            for (int i = size * N; i < size; i++, k++)
            {
                temp->data[k] = p->data[i];
                temp->ar_sz++;
                p->ar_sz--;
                p->data[i] = nullptr;
            }
            temp->data[k] = &n;
            temp->data[k + 1] = nullptr;
            temp->ar_sz++;
        }
    }
}


template<typename T>
Node<T>* List<T>::Search(int& pos) {
    if (pos < 0) {
        return nullptr;
    }
    Node<T>* cur = head;
    do {
        if (pos < cur->ar_sz)
            break;
        pos = pos - (cur->ar_sz);
        cur = cur->next;
    } while (cur != head);
    return cur;
}

template <typename T>
T* List<T>::operator[](int pos) {
    return Search(pos)->data[pos];
}

template <typename T>
void List<T>::InsertPos(T* n, int pos) {
    int l = pos;
    Node<T>* cur = Search(pos);
    cout << pos;
    if (cur->ar_sz >= size) {
        Node<T>* temp, * p;
        temp = new Node<T>;
        temp->ar_sz = 0;
        p = cur->next;
        cur->next = temp;
        temp->next = p;
        temp->prev = cur;
        p->prev = temp;
        int k = 0;
        for (int i = size * N; i < size; i++, k++)
        {
            temp->data[k] = cur->data[i];
            temp->ar_sz++;
            cur->ar_sz--;
            cur->data[i] = nullptr;
        }
        temp->data[k + 1] = nullptr;
        // temp->data[k+1] = nullptr;
        cur = Search(l);
        pos = l;
    }
    for (int i = cur->ar_sz - 1; i >= pos; i--)
        cur->data[i + 1] = cur->data[i];
    cur->data[pos] = n;
    cur->ar_sz++;
}

template <typename T>
T* List<T>::Delete(int pos) {//удаление по позиции
    Node<T>* cur = Search(pos);
    T* deleted = cur->data[pos];
    for (int i = pos; i < cur->ar_sz; i++)
        cur->data[i] = cur->data[i + 1];
    cur->ar_sz--;
    if (cur->data[0] == nullptr) {
        if (cur->next == cur)
            head = nullptr;
        else {
            if (cur == head)
                head = head->next;

            Node<T>* prev, * next;
            prev = cur->prev;
            next = cur->next;
            prev->next = cur->next;
            next->prev = cur->prev;
        }
        delete cur;
        list_sz--;
    }

    return deleted;
}

template <typename T>
void List<T>::InSort(T* n) {
    Node<T>* cur = head;
    int pos = 0, flag = 0;
    do {
        for (int i = 0; i < cur->ar_sz; i++, pos++)
            if (*cur->data[i] >= *n) {
                cout << pos;
                InsertPos(n, pos);
                flag = 1;
                break;
            }

        if (flag == 1) break;
        cur = cur->next;
    } while (cur != head);
    if (flag == 0)  Add2(*n);
}


template <typename T>
void List<T>::ListPrint() {
    Node<T>* cur = head;
    if (IsEmpty()) {
        cout << "List is empty";
        return;
    }
    do {
        cur->NodePrint();
        cur = cur->next;
        cout << "\n";
    } while (cur != head);
}

template <typename T>
Node<T>* List<T>::MinSize() {
    Node<T>* cur = head->next;
    Node<T>* min = head;
    do {
        if (cur->ar_sz < min->ar_sz)
            min = cur;
        cur = cur->next;
    } while (cur != head);
    return min;
}

template <typename T>
Node<T>* List<T>::MaxSize() {
    Node<T>* cur = head->next;
    Node<T>* max = head;
    do {
        if (cur->ar_sz > max->ar_sz)
            max = cur;
        cur = cur->next;
    } while (cur != head);
    return max;
}

template <typename T>
void List<T>::Balance() {
    Node<T>* max = MaxSize();
    Node<T>* min = MinSize();

    while (max->ar_sz - min->ar_sz > 1) {
        min->data[min->ar_sz] = max->data[max->ar_sz - 1];
        max->data[max->ar_sz - 1] = nullptr;
        min->ar_sz++;
        max->ar_sz--;
        max = MaxSize();
        min = MinSize();
    }
}


template <typename T>
void List<T>::ListPrintBack() { //учесть случай, когда список пустой
    Node<T>* cur = head;
    if (IsEmpty()) {
        cout << "List is empty";
        return;
    }
    do {
        cur = cur->prev;
        cur->NodePrint();
        cout << "\n";
    } while (cur != head);
}

template <typename T>
void List<T>::SaveToBin(ofstream& f) {
    if (f.is_open())
    {
        Node<T>* cur = head;
        do {
            f.write((char*)&cur->ar_sz, sizeof(int));
            for (int i = 0; i < cur->ar_sz; i++) {
                f.write((char*)&(*(cur->data[i])), sizeof(T));
            }
            cur = cur->next;
        } while (cur != head);
    }
}

template <typename T>
void List<T>::LoadFromBin(ifstream& f) {
    if (f.peek() == std::ifstream::traits_type::eof()) {
        cout << "! The file is empty. Save something there first\n\n";
       // return;
    }
    if (f.is_open()) {
        T* temp;
        int sz;
        if (head != nullptr)
            FreeMemory();
        while (f.peek()!=EOF) {
            f.read((char*)&sz, sizeof(int));
            temp = new T[sz];
            for(int i = 0; i<sz;i++) {
                f.read((char *) &temp[i], sizeof(T));
                Add2(temp[i]);
            }
        }
    }

}
