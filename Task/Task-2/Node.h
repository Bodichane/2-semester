#pragma once

#include <memory>

/*
* @brief Define a struct for the Node of a double linked list.
*/
struct Node
{
    int value;
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> previous;

    /*
    * @brief Constructor for Node, initializes the Node with a given value.
    * @param value The integer with which the Node will be initialized.
    */
    Node(int value);
};

