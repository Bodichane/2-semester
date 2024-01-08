#pragma once

#include <memory>

struct Node
{
    int value;
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> previous;
    Node(int value);
};

