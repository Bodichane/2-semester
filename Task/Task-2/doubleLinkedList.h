#pragma once

#include <iostream>
#include "Node.h"
#include <initializer_list>
#include <sstream>

/**
* @brief Class DoubleLinkedList.
*/
class DoubleLinkedList {
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    std::size_t size;

public:
    /**
    * @brief Constructs a new empty linked list.
    */
    DoubleLinkedList();
    /**
    * @brief Constructs a new linked list initialized with the elements of the provided initializer list.
    * @param lst The initializer list of elements to initialize the linked list with.
    */
    DoubleLinkedList(std::initializer_list<int> lst);
    /**
    * @brief Constructs a new linked list with the same elements as another linked list.
    * @param other The linked list to copy the elements from.
    */
    DoubleLinkedList(const DoubleLinkedList& other) = default;
    /**
    * @brief Move constructor for DoubleLinkedList.
    * @param other The linked list to move elements from.
    */
    DoubleLinkedList(DoubleLinkedList&& other) noexcept = default;
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
    void push_front(int value);
    /**
    * @brief Adds a new node with the given data to the back of the linked list.
    * @param data The data to store in the new node.
    */
    void push_back(int value);
    /*
    @brief a function which delete a Node in front of List.
    */
    void pop_front();
    /*
    @brief a function which delete a Node in back of List.
    */
    void pop_back();
    /**
    * @brief Returns a reference to the data stored in the node at the given index.
    * @param index The index of the node to retrieve the data from.
    * @return T& A reference to the data stored in the node at the given index.
    * @throws std::out_of_range If the index is out of bounds.
    */
    int& operator[](size_t index);
    /**
    * @brief Returns a string representation of the linked list, with the elements separated by commas and enclosed in square brackets.
    * @return std::string The string representation of the linked list.
    */
    void print();
    /**
     * @brief Removes the node at the given index from the linked list.
     * @param index The index of the node to remove.
     * @throws std::out_of_range If the index is out of bounds.
     */
    void remove(size_t index);
    /**
    * @brief Assignment Operator= for DoubleLinkedList.
    * @param other The linked list to copy the elements from.
    * @return DoubleLinkedList& A reference to the assigned linked list.
    */
    DoubleLinkedList& operator=(const DoubleLinkedList& other) = default;
    /**
    * @brief Move Assignment Operator= for DoubleLinkedList.
    * @param other The linked list to move elements from.
    * @return DoubleLinkedList& A reference to the assigned linked list.
    */
    DoubleLinkedList& operator=(DoubleLinkedList&& other) noexcept = default;

};
