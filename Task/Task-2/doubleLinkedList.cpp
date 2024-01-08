#include "doubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
    : head(nullptr), tail(nullptr), size(0) {}


DoubleLinkedList::DoubleLinkedList(std::initializer_list<int> lst)
    : DoubleLinkedList() {
    for (auto& elem : lst) {
        push_back(elem);
    }
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& other)
    : DoubleLinkedList() {
    auto cur = other.head;
    while (cur != nullptr) {
        push_back(cur->value);
        cur = cur->next;
    }
}

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList&& other) noexcept : head(nullptr), tail(nullptr), size(0) {
    std::swap(this->head, other.head);
    std::swap(this->tail, other.tail);
    std::swap(this->size, other.size);
}

DoubleLinkedList::~DoubleLinkedList() { clear(); }

void DoubleLinkedList::clear() {
    while (head) {
        head = head->next;
    }
    tail.reset();
    size = 0;
}

bool DoubleLinkedList::empty() const {
    return size == 0;
}

size_t DoubleLinkedList::length() const {
    return size;
}

void DoubleLinkedList::push_front(int value) {
    auto new_node = std::make_shared<Node>(value);
    if (head == nullptr)
    {
        tail = new_node;
    }
    else
    {
        head->previous = new_node;
    }
    new_node->next = head;
    head = new_node;
    ++size;
}

void DoubleLinkedList::push_back(int value) {
    auto new_node = std::make_shared<Node>(value);
    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        tail->next = new_node;
    }
    new_node->previous = tail;
    tail = new_node;
    ++size;
}
 
void DoubleLinkedList::pop_front()
{
    if (head == nullptr)
    {
        return;
    }
    auto temp = head;
    head = head->next;

    --size;
};

void DoubleLinkedList::pop_back()
{
    if (nullptr == this->head)
    {
        return;
    }

    auto temp = this->tail;
    this->tail = this->tail->previous.lock();

    tail->next = nullptr;
    --size;
};


int& DoubleLinkedList::operator[](size_t index) {
    auto curr = head.get();
    for (size_t i = 0; i < index; ++i) {
        if (!curr) throw std::out_of_range("Index out of bounds");
        curr = curr->next.get();
    }
    if (!curr) throw std::out_of_range("Index out of bounds");
    return curr->value;
}

void DoubleLinkedList::print() {

    auto temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
}
 
void DoubleLinkedList::remove(size_t index) {
    if (index == 0)
    {
        pop_front();
    }
    else if (index == size - 1)
    {
        pop_back();
    }
    else
    {
        auto temp = head;
        std::size_t i = 0;
        while (i < index - 1)
        {
            temp = temp->next;
        }

        auto to_delete = temp->next;
        temp->next = to_delete->next;
        --size;
    }
}

DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList& other) {
    if (this == &other) return *this;
    clear();
    for (auto curr = other.head; curr; curr = curr->next) {
        push_back(curr->value);
    }
    return *this;
}

DoubleLinkedList& DoubleLinkedList::operator=(DoubleLinkedList&& other) noexcept {
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




