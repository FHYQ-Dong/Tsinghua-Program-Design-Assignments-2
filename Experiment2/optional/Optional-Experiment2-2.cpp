#include <iostream>
#include <vector>

template <typename T>
inline void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
class Node;
template <typename T>
class __List_iterator;
template <typename T>
class List;

template <typename T>
class Node {
    public:
        T data;
        Node *next, *prev;
        Node();
        Node(const T &data);
        Node(const Node &n);
        ~Node();
};

template <typename T>
class __List_iterator {
    private:
        Node<T> *ptr;

    friend class List<T>;

    public:
        __List_iterator();
        __List_iterator(Node<T> *ptr);
        __List_iterator(const __List_iterator &it);
        ~__List_iterator();
        __List_iterator &operator++();
        __List_iterator &operator--();
        T &operator*();
        bool operator==(const __List_iterator &it);
        bool operator!=(const __List_iterator &it);
};

template <typename T>
class List {
    private:
        Node<T> *head, *tail;
        size_t sz;

    public:
        using iterator = __List_iterator<T>;
        List();
        List(const T data[], size_t size);
        List(const List &l);
        ~List();
        void push_back(const T &data);
        void push_front(const T &data);
        void insert(iterator it, const T &data);
        void pop_back();
        void pop_front();
        void erase(iterator it);
        void erase(iterator first, iterator last);
        void remove(const T &data);
        void remove_all(const T &data);
        void clear();
        void reverse();
        iterator find_the_first(const T &data);
        iterator find_the_last(const T &data);
        iterator find_the_next(const T &data, const iterator &it);
        iterator find_the_prev(const T &data, const iterator &it);
        void print();
        iterator begin();
        iterator end();
};

template <typename T>
Node<T>::Node() {
    next = prev = nullptr;
}
template <typename T>
Node<T>::Node(const T &data) {
    this->data = data;
    next = prev = nullptr;
}
template <typename T>
Node<T>::Node(const Node &n) {
    data = n.data;
    next = prev = nullptr;
}
template <typename T>
Node<T>::~Node() {
    next = prev = nullptr;
}

template <typename T>
__List_iterator<T>::__List_iterator() {
    ptr = nullptr;
}
template <typename T>
__List_iterator<T>::__List_iterator(Node<T> *ptr) {
    this->ptr = ptr;
}
template <typename T>
__List_iterator<T>::__List_iterator(const __List_iterator<T> &it) {
    ptr = it.ptr;
}
template <typename T>
__List_iterator<T>::~__List_iterator() {
    ptr = nullptr;
}
template <typename T>
__List_iterator<T>& __List_iterator<T>::operator++() {
    ptr = ptr->next;
    return *this;
}
template <typename T>
__List_iterator<T>& __List_iterator<T>::operator--() {
    ptr = ptr->prev;
    return *this;
}
template <typename T>
T& __List_iterator<T>::operator*() {
    return ptr->data;
}
template <typename T>
bool __List_iterator<T>::operator==(const __List_iterator<T> &it) {
    return ptr == it.ptr;
}
template <typename T>
bool __List_iterator<T>::operator!=(const __List_iterator<T> &it) {
    return ptr != it.ptr;
}

template <typename T>
List<T>::List() {
    head = tail = nullptr;
    sz = 0;
}
template <typename T>
List<T>::List(const T data[], size_t size) {
    head = tail = nullptr;
    sz = 0;
    for (size_t i = 0; i < size; i++) {
        push_back(data[i]);
    }
}
template <typename T>
List<T>::List(const List &l) {
    head = tail = nullptr;
    sz = 0;
    for (Node<T> *p = l.head; p != nullptr; p = p->next) {
        push_back(p->data);
    }
}
template <typename T>
List<T>::~List() {
    clear();
}
template <typename T>
void List<T>::push_back(const T &data) {
    Node<T> *p = new Node<T>(data);
    if (head == nullptr) {
        head = tail = p;
    }
    else {
        tail->next = p;
        p->prev = tail;
        tail = p;
    }
    sz++;
}
template <typename T>
void List<T>::push_front(const T &data) {
    Node<T> *p = new Node<T>(data);
    if (head == nullptr) {
        head = tail = p;
    }
    else {
        head->prev = p;
        p->next = head;
        head = p;
    }
    sz++;
}
template <typename T>
void List<T>::insert(List<T>::iterator it, const T &data) {
    Node<T> *p = new Node<T>(data);
    if (it.ptr == nullptr) {
        push_back(data);
    }
    else if (it.ptr == head) {
        push_front(data);
    }
    else {
        p->next = it.ptr;
        p->prev = it.ptr->prev;
        it.ptr->prev->next = p;
        it.ptr->prev = p;
        sz++;
    }
}
template <typename T>
void List<T>::pop_back() {
    if (tail == nullptr) {
        return;
    }
    Node<T> *p = tail;
    tail = tail->prev;
    if (tail == nullptr) {
        head = nullptr;
    }
    else {
        tail->next = nullptr;
    }
    delete p;
    sz--;
}
template <typename T>
void List<T>::pop_front() {
    if (head == nullptr) {
        return;
    }
    Node<T> *p = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    else {
        head->prev = nullptr;
    }
    delete p;
    sz--;
}
template <typename T>
typename List<T>::iterator List<T>::begin() {
    return iterator(head);
}
template <typename T>
typename List<T>::iterator List<T>::end() {
    return iterator(nullptr);
}
template <typename T>
void List<T>::erase(List<T>::iterator it) {
    if (it.ptr == nullptr) {
        return;
    }
    if (it.ptr == head) {
        pop_front();
    }
    else if (it.ptr == tail) {
        pop_back();
    }
    else {
        it.ptr->prev->next = it.ptr->next;
        it.ptr->next->prev = it.ptr->prev;
        delete it.ptr;
        sz--;
    }
}
template <typename T>
void List<T>::erase(List<T>::iterator first, List<T>::iterator last) {
    while (first != last) {
        erase(first++);
    }
}
template <typename T>
void List<T>::remove(const T &data) {
    for (Node<T> *p = head; p != nullptr; p = p->next) {
        if (p->data == data) {
            erase(iterator(p));
            break;
        }
    }
}
template <typename T>
void List<T>::remove_all(const T &data) {
    for (Node<T> *p = head; p != nullptr; ) {
        Node<T> *temp = p->next;
        if (p->data == data) {
            erase(iterator(p));
        }
        p = temp;
    }
}
template <typename T>
void List<T>::clear() {
    while (head != nullptr) {
        pop_front();
    }
}
template <typename T>
void List<T>::reverse() {
    Node<T> *p = head;
    while (p != nullptr) {
        swap(p->next, p->prev);
        p = p->prev;
    }
    swap(head, tail);
}
template <typename T>
typename List<T>::iterator List<T>::find_the_first(const T &data) {
    for (Node<T> *p = head; p != nullptr; p = p->next) {
        if (p->data == data) {
            return iterator(p);
        }
    }
    return end();
}
template <typename T>
typename List<T>::iterator List<T>::find_the_last(const T &data) {
    for (Node<T> *p = tail; p != nullptr; p = p->prev) {
        if (p->data == data) {
            return iterator(p);
        }
    }
    return end();
}
template <typename T>
typename List<T>::iterator List<T>::find_the_next(const T &data, const iterator &it) {
    for (Node<T> *p = it.ptr->next; p != nullptr; p = p->next) {
        if (p->data == data) {
            return iterator(p);
        }
    }
    return end();
}
template <typename T>
typename List<T>::iterator List<T>::find_the_prev(const T &data, const iterator &it) {
    for (Node<T> *p = it.ptr->prev; p != nullptr; p = p->prev) {
        if (p->data == data) {
            return iterator(p);
        }
    }
    return end();
}
template <typename T>
void List<T>::print() {
    for (Node<T> *p = head; p != nullptr; p = p->next) {
        std::cout << p->data << " ";
    }
    std::cout << std::endl;
}

inline void test() {
    int a[] = {1, 2, 3, 4, 5};
    List<int> l(a, 5);
    l.print(); // l = {1, 2, 3, 4, 5}
    l.push_back(6);
    l.print(); // l = {1, 2, 3, 4, 5, 6}
    l.push_front(0);
    l.print(); // l = {0, 1, 2, 3, 4, 5, 6}
    List<int>::iterator it = l.begin();
    std::cout << *it << std::endl; // 0
    l.insert(it, -1);
    l.print(); // l = {-1, 0, 1, 2, 3, 4, 5, 6}
    l.pop_back();
    l.print(); // l = {-1, 0, 1, 2, 3, 4, 5}
    l.pop_front();
    l.print(); // l = {0, 1, 2, 3, 4, 5}
    std::cout << *l.find_the_first(3) << std::endl; // 3
    l.erase(l.find_the_first(3));
    l.print(); // l = {0, 1, 2, 4, 5}
    std::cout << (l.find_the_first(3)==l.end() ? "true" : "false") << std::endl; // true
    l.remove(4);
    l.print(); // l = {0, 1, 2, 5}
    l.insert(l.find_the_first(5), 3); l.insert(l.find_the_first(5), 3);
    l.print(); // l = {0, 1, 2, 3, 3, 5}
    l.remove_all(3);
    l.print(); // l = {0, 1, 2, 5}
    l.reverse();
    l.print(); // l = {5, 2, 1, 0}
    List<int> l2 = l;
    l2.print(); // l2 = {5, 2, 1, 0}
}

int main() {
    test();
    return 0;
}