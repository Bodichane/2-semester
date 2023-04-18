#include "doubleLinkedList.h"

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
    : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(std::initializer_list<T> lst)
    : DoubleLinkedList() {
  for (auto &elem : lst) {
    push_back(elem);
  }
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList &other)
    : DoubleLinkedList() {
  Node *cur = other.head;
  while (cur != nullptr) {
    push_back(cur->data);
    cur = cur->next;
  }
}

template <typename T> DoubleLinkedList<T>::~DoubleLinkedList() { clear(); }

template <typename T> void DoubleLinkedList<T>::clear() {
  Node *cur = head;
  while (cur != nullptr) {
    Node *next = cur->next;
    delete cur;
    cur = next;
  }
  head = nullptr;
  tail = nullptr;
  size = 0;
}

template <typename T> bool DoubleLinkedList<T>::empty() const {
  return size == 0;
}

template <typename T> size_t DoubleLinkedList<T>::length() const {
  return size;
}

template <typename T> void DoubleLinkedList<T>::push_front(const T &data) {
  Node *node = new Node(data);
  if (empty()) {
    head = node;
    tail = node;
    head->prev = tail;
    tail->next = head;
  } else {
    node->next = head;
    head->prev = node;
    head = node;
    head->prev = tail;
    tail->next = head;
  }
  size++;
}

template <typename T> void DoubleLinkedList<T>::push_back(const T &data) {
  Node *node = new Node(data);
  if (empty()) {
    head = node;
    tail = node;
    head->prev = tail;
    tail->next = head;
  } else {
    node->prev = tail;
    tail->next = node;
    tail = node;
    head->prev = tail;
    tail->next = head;
  }
  size++;
}

template <typename T> T &DoubleLinkedList<T>::operator[](size_t index) {
  if (index < 0 || index >= size) {
    throw std::out_of_range("Index out of range");
  }
  Node *cur = head;
  for (size_t i = 0; i < index; i++) {
    cur = cur->next;
  }
  return cur->data;
}

template <typename T>
const T &DoubleLinkedList<T>::operator[](size_t index) const {
  if (index < 0 || index >= size) {
    throw std::out_of_range("Index out of range");
  }
  Node *cur = head;
  for (size_t i = 0; i < index; i++) {
    cur = cur->next;
  }
  return cur->data;
}

template <typename T> std::string DoubleLinkedList<T>::to_string() const {
  std::stringstream ss;
  if (empty()) {
    ss << "[]";
  } else {
    ss << "[" << head->data;
    Node *cur = head->next;
    while (cur != head) {
      ss << ", " << cur->data;
      cur = cur->next;
    }
    ss << "]";
  }
  return ss.str();
}

template <typename T> void DoubleLinkedList<T>::remove(size_t index) {
  if (index < 0 || index >= size) {
    throw std::out_of_range("Index out of range");
  }
  if (size == 1) {
    clear();
  } else {
    Node *cur = head;
    for (size_t i = 0; i < index; i++) {
      cur = cur->next;
    }
    if (cur == head) {
      head = head->next;
    }
    if (cur == tail) {
      tail = tail->prev;
    }
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
    size--;
  }
}
