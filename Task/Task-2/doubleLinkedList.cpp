#include "doubleLinkedList.h"

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
    : start(nullptr), end(nullptr), size(0) {}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(std::initializer_list<T> lst)
    : DoubleLinkedList() {
    for (auto& elem : lst) {
        addNode(elem);
    }
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList& other)
    : DoubleLinkedList() {
    Node* cur = other.start;
    while (cur != nullptr) {
        addNode(cur->data);
        cur = cur->next;
    }
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(DoubleLinkedList&& other) noexcept : start(nullptr), end(nullptr), size(0) {
    std::swap(this->start, other.start);
    std::swap(this->end, other.end);
    std::swap(this->size, other.size);
}

template <typename T> DoubleLinkedList<T>::~DoubleLinkedList() { clear(); }

template <typename T> void DoubleLinkedList<T>::clear() {
    while (start) {
        auto sp = end.lock();
        end = start->next;
        start.reset(sp.get());
    }
}

template <typename T> bool DoubleLinkedList<T>::empty() const {
    return size == 0;
}

template <typename T> size_t DoubleLinkedList<T>::length() const {
    return size;
}

template <typename T> void DoubleLinkedList<T>::addNode(const T& data) {
    std::unique_ptr<Node> new_node = std::make_unique<Node>(data);
    if (size == 0) {
        start.reset(new_node);
        start->data = data;
        end = start;
    }
    else {
        auto sp = end.lock();
        auto sp2 = end.lock();
        sp->next.reset(new_node);
        sp.reset(sp->next.get());
        sp->prev = sp2;
        sp->data = data;
        std::cout << "Value size is " << size << " " << sp->data << std::endl;
        end = sp;
    }
    size++;
}

template <typename T> T& DoubleLinkedList<T>::operator[](size_t index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    Node* cur = start;
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
        ss << "[" << start->data;
        Node* cur = start->next;
        while (cur != start) {
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
        // Removing the first node
        start = std::move(start->next);
        if (start) {
            start->prev = nullptr;
        }
        else {
            end = nullptr;
        }
    }
    else {
        std::unique_ptr<Node>* current = &start;
        for (size_t i = 0; i < index; ++i) {
            current = &(*current)->next;
        }

        std::unique_ptr<Node> nodeToRemove = std::move(*current);
        *current = std::move(nodeToRemove->next);

        if (*current) {
            (*current)->prev = nodeToRemove->prev;
        }
        else {
            // Removing the last node
            end = nodeToRemove->prev;
        }
    }
    size--;
}

template <typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList& other) {
    if (this != &other) {
        clear();
        for (Node* curr = other.start; curr != nullptr; curr = curr->next) {
            push_back(curr->data);
        }
    }
    return *this;
}
template <typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(DoubleLinkedList&& other) noexcept {
    if (this != &other) {
        std::swap(this->start, other.start);
        std::swap(this->end, other.end);
        std::swap(this->size, other.size);

        other.start = nullptr;
        other.end = 0;
        other.size = 0;
    }
    return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const DoubleLinkedList<T>& lst) {
    os << lst.to_string();
    return os;
}



