#include "Elevator.h"

elevator::elevator() {
	headPtr = nullptr;
	tailPtr = nullptr;

	int floor = 0;
	char direction = 'n';
}


bool elevator::empty() {
	if (headPtr == nullptr) {
		return true;
	}
	else {
		return false;
	}

}

void elevator::push_front(int floor) {
	node* frontNode = new node;
	frontNode->floor = floor;

	if (headPtr == nullptr) { //if list is empty, set headprt and tailptr as frontNode 
		headPtr = frontNode;
		tailPtr = frontNode;
	}
	else { // add to front
		frontNode->next = headPtr;
		headPtr->prev = frontNode;
		headPtr = frontNode;
	}
}

void elevator::push_back(int floor) {
	node* backNode = new node;
	backNode->floor = floor;

	if (headPtr == nullptr) { //if list is empty, set headptr and tailptr as backNode 
		headPtr = backNode;
		tailPtr = backNode;
	}
	else { // push to back
		tailPtr->next = backNode;
		tailPtr = backNode;
	}
}

void elevator::insert(int input, int floor) {

	if (empty() || input == 0) {
		push_front(floor);
	}
	else if (input == 1) {
		node* tempPtr = headPtr;
		node* insertNode = new node;

		insertNode->floor = floor;

		tempPtr->next = insertNode;
		insertNode->prev = tempPtr;



	}
	else {
		node* tempPtr = headPtr;   //let tempNode be headptr
		node* insertNode = new node;

		node* prevPtr;
		node* nextPtr;

		//move tempNode to position input
		for (int i = 0; i < input; i++) {
			tempPtr = tempPtr->next;
			if (tempPtr == nullptr)
				break;
		}

		if (tempPtr == nullptr) {
			push_back(floor);
		}
		else {
			//assign floor to insertNode
			insertNode->floor = floor;

			nextPtr = tempPtr;        //assign tempNode position to nextNode
			prevPtr = tempPtr->prev;  //point prevNode to tempNode

			//put insertNode between next and prev nodes
			insertNode->next = nextPtr;
			insertNode->prev = prevPtr;
			//insertNode = tempPtr;
			//insertNode->prev = tempPtr->prev;
			//insertNode->next = tempPtr->next;

			//change prev and next node to point to insert node
			prevPtr->next = insertNode;
			nextPtr->prev = insertNode;
		}

	}


}

void elevator::print() {
	if (empty()) {
		cout << "Empty list" << endl;
	}
	else {
		node* tempPtr = headPtr;
		cout << "List: " << endl;
		while (tempPtr != nullptr) {
			cout << tempPtr->floor << " ";
			tempPtr = tempPtr->next;
		}
	}

	cout << "\n\n";

}
