#pragma once
//#include <iostream>

//using namespace std;

template <typename T>
class queue {
	class node {
		T _value;
		node* _next;
	public:
		node (T value) {
			_value = value;
			_next = nullptr;
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
			_next=next;
		}

		~node() {
		}

	};

private:
	node* _head;
	int _size;

	node getBack() {
		node* node = _head;
		while ((*node).getNext() != nullptr)
			node = (*node).getNext();
		return *node;
	}
public:
	queue() { 
		_head = nullptr; 
		_size = 0;
	}
	bool isEmpty() {
		return (_head==nullptr);
	}
	T front() {
		return _head->getValue();
	}
	T back() {
		return getBack().getValue();
	}

	int size() {
		return _size;
	}

	T pop(){
		node* node = _head;
		_head = _head->getNext();
		_size--;
		//delete 
		return (*node).getValue();
	}

	void push(T value) {
		node *newNode=new node(value);
		if (_head == nullptr) _head = newNode;
		else getBack().setNext(newNode);
		_size++;
	}
};
