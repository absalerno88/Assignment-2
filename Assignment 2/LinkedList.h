#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>
#include <stdexcept>
#include <iostream>

template<typename Item_Type>
class Single_Linked_List {
private:
    // Node class definition
    class Node {
    public:
        Item_Type data;
        Node* next;

        Node(const Item_Type& data_item, Node* next_ptr = nullptr)
            : data(data_item), next(next_ptr) {}    
    };

    // Data members of Single_linked_List
    Node* head;
    Node* tail;
    std::size_t num_items;

public:
    // Constructor
    Single_Linked_List();

    // Destructor
    ~Single_Linked_List();

    // Member function prototypes
    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    void pop_front();
    void pop_back();
    bool empty() const;
    const Item_Type& front() const;
    const Item_Type& back() const;
    void insert(std::size_t index, const Item_Type& item);
    bool remove(std::size_t index);
    std::size_t find(const Item_Type& item) const;
    std::size_t size() const;
    void print() const;
};


// Constructor
template<typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor
template<typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (!empty()) {
        pop_front();
    }
}

// push_front method
template<typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    head = new Node(item, head);
    if (tail == nullptr) {
        tail = head;
    }
    num_items++;
}

// push_back method
template<typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (tail != nullptr) {
        tail->next = new_node;
        tail = new_node;
    } else {
        head = tail = new_node;
    }
    num_items++;
}

// pop_front method
template<typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) {
        throw std::out_of_range("List is empty.");
    }
    Node* temp_ptr = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp_ptr;
    num_items--;
}

// pop_back method
template<typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (empty()) {
        throw std::out_of_range("List is empty.");
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }
        prev->next = nullptr;
        delete tail;
        tail = prev;
    }
    num_items--;
}

// front method
template<typename Item_Type>
const Item_Type& Single_Linked_List<Item_Type>::front() const {
    if (empty()) {
        throw std::out_of_range("List is empty.");
    }
    return head->data;
}

// back method
template<typename Item_Type>
const Item_Type& Single_Linked_List<Item_Type>::back() const {
    if (empty()) {
        throw std::out_of_range("List is empty.");
    }
    return tail->data;
}

// empty method
template<typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return head == nullptr;
}

// insert method
template<typename Item_Type>
void Single_Linked_List<Item_Type>::insert(std::size_t index, const Item_Type& item) {
    if (index > num_items) {
        push_back(item);
        return;
    }
    if (index == 0) {
        push_front(item);
        return;
    }
    Node* prev = head;
    for (std::size_t i = 1; i < index; ++i) {
        prev = prev->next;
    }
    prev->next = new Node(item, prev->next);
    if (prev->next->next == nullptr) {
        tail = prev->next;
    }
    num_items++;
}

// remove method
template<typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(std::size_t index) {
    if (index >= num_items || empty()) {
        return false;
    }
    if (index == 0) {
        pop_front();
        return true;
    }
    if (index == num_items - 1) {
        pop_back();
        return true;
    }
    Node* prev = head;
    for (std::size_t i = 1; i < index; ++i) {
        prev = prev->next;
    }
    Node* to_remove = prev->next;
    prev->next = to_remove->next;
    delete to_remove;
    num_items--;
    return true;
}

// find method
template<typename Item_Type>
std::size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    std::size_t index = 0;
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        if (curr->data == item) {
            return index;
        }
        index++;
    }
    return num_items;
}

// size method
template<typename Item_Type>
std::size_t Single_Linked_List<Item_Type>::size() const {
    return num_items;
}

// print method
template<typename Item_Type>
void Single_Linked_List<Item_Type>::print() const {
    Node* current = head;
    while(current) {
        std::cout << current->data << "  ";
        current = current->next;
    }
    std::cout << std::endl;
}



#endif // LINKEDLIST_H
