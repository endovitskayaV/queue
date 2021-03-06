#pragma once
#include <iterator>

template <typename T>
class queue {

    class node {
    private:
        T _value;
        node* _next;
    public:
        node(T value) {
            _value = value;
            _next = nullptr;
        }

        ~node() {
        }

        void setValue(T value) {
            _value = value;
        }

        T getValue() {
            return _value;
        }

        node* getNext() {
            return _next;
        }

        void setNext(node* next) {
            _next = next;
        }

    };

private:
    node* _head;
    int _size;

    node* getBackNode() {
        node *node = _head;
        while (node->getNext() != nullptr)
            node = node->getNext();
        return node;
    }

public:
    class  myIterator : public std::iterator<std::output_iterator_tag, T, int, const T*, T> {
    private:
        node* _currNode;

    public:
        explicit myIterator(node* curNode) {
            _currNode = curNode;
        }

        myIterator& operator++() {
            _currNode = _currNode->getNext();
            return *this;
        }
        myIterator operator++(int) { myIterator retval = *this; ++(*this); return retval; }
        bool operator==(myIterator other) const { return _currNode == other._currNode;}
        bool operator!=(myIterator other) const { return !(*this == other); }
        T operator*() { return _currNode->getValue(); }
    };

    queue() {
        _head = nullptr;
        _size = 0;
    }

    bool isEmpty() {
        return (_size == 0);
    }

    T front() {
        if (isEmpty())
            throw "queue is empty";
        return _head->getValue();
    }

    T back() {
        if (isEmpty())
            throw "queue is empty";
        return getBackNode()->getValue();
    }

    int size() {
        return _size;
    }

    T pop() {
        if (isEmpty()) throw "queue is empty";
        else {
            _size--;
            T value = _head->getValue();
            _head = _head->getNext();
            return value;
        }
    }

    void push(T value) {
        node *newNode = new node(value);
        if (_head == nullptr) _head = newNode;
        else getBackNode()->setNext(newNode);
        _size++;
    }

    myIterator begin() {
        return myIterator(_head);
    }

    myIterator end() {
        return myIterator(nullptr);
    }

};


