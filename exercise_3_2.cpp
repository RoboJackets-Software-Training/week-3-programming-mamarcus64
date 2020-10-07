#include "exercise_3_2.hpp"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
}

void LinkedList::add_to_front(string name) {
    unique_ptr<Node> new_head = make_unique<Node>();
    new_head->name = name;
    new_head->next = move(head);
    head = move(new_head);
}

void LinkedList::add_to_back(string name){
	if (head == nullptr) {
		add_to_front(name);
	} else {
    	unique_ptr<Node> new_back = make_unique<Node>();
   		new_back->name = name;
   		Node* curr = head.get();
   		while(curr->next.get() != nullptr) {
   			curr = curr->next.get();
   		}
   		curr->next = move(new_back);
	}

}

void LinkedList::add_at_index(string name, int index) {
    if (index < 0) {
    	return;
    } else if (index == 0) {
    	add_to_front(name);
    } else {
    	unique_ptr<Node> new_node = make_unique<Node>();
    	new_node->name = name;
    	Node* curr = head.get();
    	for(int i = 0; i < index - 1; i++) {
    		if (curr == nullptr) {
    			return;
    		}
    		curr = curr->next.get();
    	}
    	new_node->next = move(curr->next);
    	curr->next = move(new_node);
    }
}

void LinkedList::remove_from_front() {
    if (head == nullptr) {
    	return;
    } else {
    	head = move(head->next);
    }
}

void LinkedList::remove_from_back() {
    if (head == nullptr) {
    	return;
    } else {
    	Node* curr = head.get();
   		while(curr->next.get() != nullptr) {
   			curr = curr->next.get();
   		}
   		curr->next = nullptr;
    }
}

void LinkedList::remove_at_index(int index) {
	if (head == nullptr) {
	    	return;
	    } else {
	    	Node* curr = head.get();
	    	for(int i = 0; i < index - 1; i++) {
	    		if (curr == nullptr) {
	    			return;
	    		}
	    		curr = curr->next.get();
	    	}
	   		curr->next = move(curr->next->next);
	    }
}

void LinkedList::print_names() {
    Node* curr = head.get();
    while (curr != nullptr) {
    	cout << curr->name << "\t";
    	curr = curr->next.get();
    }
    cout << endl;
}
