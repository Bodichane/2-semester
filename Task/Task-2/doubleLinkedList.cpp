#include "doubleLinkedList.h"

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
    : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(std::initializer_list<T> lst)
    : DoubleLinkedList() {
    for (auto& elem : lst) {
        push_back(elem);
    }
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList& other)
    : DoubleLinkedList() {
    auto cur = other.head;
    while (cur != nullptr) {
        push_back(cur->data);
        cur = cur->next;
    }
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(DoubleLinkedList&& other) noexcept : head(nullptr), tail(nullptr), size(0) {
    std::swap(this->head, other.head);
    std::swap(this->tail, other.tail);
    std::swap(this->size, other.size);
}

template <typename T> DoubleLinkedList<T>::~DoubleLinkedList() { clear(); }

template <typename T> void DoubleLinkedList<T>::clear() {
    while (head) {
        auto sp = tail.lock();
        tail = head->next;
        head.reset(sp.get());
    }
}

template <typename T> bool DoubleLinkedList<T>::empty() const {
    return size == 0;
}

template <typename T> size_t DoubleLinkedList<T>::length() const {
    return size;
}

template <typename T> void DoubleLinkedList<T>::push_front(const T& data) {
    auto new_node = std::make_unique<Node>(data);
    if (head == nullptr) {
        tail = new_node;
    }
    else {
        head->prev = new_node;
    }
    ++size;
}

template <typename T> void DoubleLinkedList<T>::push_back(const T& data) {
    auto new_node = std::make_unique<Node>(data);
    if (head == 0) {
        tail = new_node;
    }
    else {
        tail->next = new_node;
    }
    new_node->prev = tail;
    tail = new_node;
    ++size;
}

template <typename T> T& DoubleLinkedList<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    Node* cur = head;
    for (size_t i = 0; i < index; i++) {
        cur = cur->next;
    }
    return cur->data;
}

template <typename T> std::string DoubleLinkedList<T>::to_string() const {
    std::stringstream ss;
    if (empty()) {
        ss << "[]";
    }
    else {
        ss << "[" << head->data;
        Node* cur = head->next;
        while (cur != head) {
            ss << ", " << cur->data;
            cur = cur->next;
        }
        ss << "]";
    }
    return ss.str();
}

template <typename T> void DoubleLinkedList<T>::remove(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index is out of bounds");
    }

    if (index == 0) {
        head = std::move(head->next);
        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
    }
    else {
        std::unique_ptr<Node>* current = &head;
        for (size_t i = 0; i < index; ++i) {
            current = &(*current)->next;
        }

        std::unique_ptr<Node> nodeToRemove = std::move(*current);
        *current = std::move(nodeToRemove->next);

        if (*current) {
            (*current)->prev = nodeToRemove->prev;
        }
        else {
            tail = nodeToRemove->prev;
        }
    }
    size--;
}

template <typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList& other) {
    if (this != &other) {
        clear();
        for (Node* curr = other.head; curr != nullptr; curr = curr->next) {
            push_back(curr->data);
        }
    }
    return *this;
}
template <typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(DoubleLinkedList&& other) noexcept {
    if (this != &other) {
        std::swap(this->head, other.head);
        std::swap(this->tail, other.tail);
        std::swap(this->size, other.size);

        other.head = nullptr;
        other.tail = 0;
        other.size = 0;
    }
    return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const DoubleLinkedList<T>& lst) {
    os << lst.to_string();
    return os;
}



