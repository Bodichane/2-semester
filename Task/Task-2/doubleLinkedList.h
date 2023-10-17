
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <initializer_list>
#include <sstream>
#include <stdexcept>

template <typename T> class DoubleLinkedList {
private:
  struct Node {
    T data;
    Node *next;
    Node *prev;
    Node(const T &data) : data(data), next(nullptr), prev(nullptr) {}
  };

  Node *head;
  Node *tail;
  size_t size;

public:
  /**
  * @brief Constructs a new empty linked list.
  */
  DoubleLinkedList();
  /**
  * @brief Constructs a new linked list initialized with the elements of the provided initializer list.
  * @param lst The initializer list of elements to initialize the linked list with.
  */
  DoubleLinkedList(std::initializer_list<T> lst);
  /**
  * @brief Constructs a new linked list with the same elements as another linked list.
  * @param other The linked list to copy the elements from.
  */
  DoubleLinkedList(const DoubleLinkedList &other);
  /**
  * @brief Destroys the linked list and deallocates the memory used by the nodes.
  */
  ~DoubleLinkedList();
  /**
  * @brief Removes all nodes from the linked list.
  */
  void clear();
  /**
  * @brief Checks if the linked list is empty.
  * @return true If the linked list is empty.
  * @return false If the linked list is not empty.
  */
  bool empty() const;
  /**
  * @brief Returns the number of nodes in the linked list.
  * @return size_t The number of nodes in the linked list.
  */
  size_t length() const;
  /**
  * @brief Adds a new node with the given data to the front of the linked list.
  * @param data The data to store in the new node.
  */
  void push_front(const T &data);
  /**
  * @brief Adds a new node with the given data to the back of the linked list.
  * @param data The data to store in the new node.
  */
  void push_back(const T &data);
  /**
  * @brief Returns a reference to the data stored in the node at the given index.
  * @param index The index of the node to retrieve the data from.
  * @return T& A reference to the data stored in the node at the given index.
  * @throws std::out_of_range If the index is out of bounds.
  */
  T &operator[](size_t index);
  /**
  * @brief Returns a string representation of the linked list, with the elements separated by commas and enclosed in square brackets.
  * @return std::string The string representation of the linked list.
  */
  std::string to_string() const;
  /**
   * @brief Removes the node at the given index from the linked list.
   * @param index The index of the node to remove.
   * @throws std::out_of_range If the index is out of bounds.
   */
  void remove(size_t index); 

  auto operator<=>(const const DoubleLinkedList<T>) const = default;
};

#endif
