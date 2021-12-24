#include <iostream>
#include "List.h"
#define N 0.5
using namespace std;

template<typename T>
List<T>::List() {
    head = nullptr;
    list_sz = 0;
}

template<typename T>
bool List<T>::IsEmpty() {
    if (list_sz == 0)
        return true;
    else
        return false;
}

template<typename T>
void List<T>::Add(T& n) {//добавление в конец списка
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
            temp = new Node<T>;
            p = head->prev;
            head->prev = temp;
            temp->prev = p;
            temp->next = head;
            p->next = temp;
            temp->ar_sz = 1;
            list_sz++;
            temp->data[0] = &n;
            temp->data[1] = nullptr;
        }
    }
}




template <typename T>
T* List<T>::Delete(int pos) {//удаление по позиции
    if (pos < 0) {
        return nullptr;
    }
    Node<T>* cur = head;
    T* deleted;
    while (true) {
        if (pos < cur->ar_sz)
            break;
        pos = pos - (cur->ar_sz);
        cur = cur->next;
    }
    deleted = cur->data[pos];
    cur->ar_sz;
    for (int i = pos + 1; i < cur->ar_sz + 1; i++)
        cur->data[i - 1] = cur->data[i];
    cur->ar_sz--;
    if (cur->data[0] == nullptr) {
        if (cur == head) {
            head = head->next;
        }
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        list_sz--;
        delete cur;
    }
    return deleted;
}


template <typename T>
void List<T>::ListPrint() {//учесть случай, когда список пустой
    Node<T>* cur = head;
    do {
        for (int i = 0; cur->data[i] != nullptr; i++)
            cout << *(cur->data[i]) << " ";
        cur = cur->next;
        cout << "\n";
    } while (cur != head);
}

template <typename T>
void List<T>::ListPrintBack() { //учесть случай, когда список пустой
    Node<T>* cur = head;
    do {
        cur = cur->prev;
        for (int i = 0; cur->data[i] != nullptr; i++)
            cout << *(cur->data[i]) << " ";
        cout << "\n";
    } while (cur != head);
}

