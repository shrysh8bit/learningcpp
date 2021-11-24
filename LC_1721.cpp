// Allocate memeory inside heap during run time using pointer

// #include<iostream>

// using namespace std;

// struct Node{
// 	int data;
// 	struct Node *next;
// };

// Node * enter_values(Node *start, int number){

// 	Node *traverse = new Node;

// 	traverse->data = number;
// 	traverse->next = start;

// 	start = traverse;

// 	cout << start << endl;
// 	cout << start->data << endl;
// 	cout << start->next << endl;

// 	return start;
// }

// void read_values(Node *start){
// 		Node *traverse;
// 		traverse = start;

// 	while(traverse != NULL){
// 		cout << traverse->data << endl;
// 		traverse = traverse->next;
// 	}
// }

// int main(){
// 	Node *start = NULL;

// 	start = enter_values(start, 5);
// 	start = enter_values(start, 15);
// 	start = enter_values(start, 25);
// 	start = enter_values(start, 35);
	
// 	read_values(start);



// return 0;

// }


// #include<iostream>

// using namespace std;

// struct Node{
// 	int data;
// 	Node *next;
// };

// void enter_values(Node **start, int number){

// 	// Node *temp = new Node;

// 	if (*start == NULL){
// 		*start = new Node;
// 		(*start)->data = number;
// 		(*start)->next = NULL;

// 		return;
// 	}

// 	Node *lead = *start;

// 	while (lead->next != NULL && (lead->next)->data < number){
// 		lead = lead->next;
// 	}

// 	Node *temp = new Node;
	
// 	temp->next = lead->next;
// 	temp->data = number;
// 	lead->next = temp;
	

// 	return;
// }

// void read_values(Node *start){
// 		Node *traverse;
// 		traverse = start;

// 	while(traverse != NULL){
// 		cout << traverse->data << endl;
// 		traverse = traverse->next;
// 	}
// }

// int main(){
// 	Node *start = NULL;

// 	enter_values(&start, 5);
// 	enter_values(&start, 15);
// 	enter_values(&start, 25);
// 	enter_values(&start, 20);
	
// 	read_values(start);



// return 0;

// }



// #include<iostream>

// using namespace std;


// struct Node{
// 	int data;
// 	Node *next;
// };

// Node* ll_insert(Node* head, int number){

// 	if (head == NULL){
// 		head = new Node;
// 		head->data = number;
// 		head->next = NULL;
// 		// cout << head << endl;
// 		return head;
// 	}

// 	Node* traverse;
// 	traverse = head;

// 	while(traverse->next != NULL){
// 		traverse = traverse->next;
// 	}

// 	traverse->next = new Node;
// 	traverse = traverse->next;
// 	traverse->data = number;
// 	traverse->next = NULL;
// 	// cout << head->data << endl;

// 	return head;

// }

// Node* ll_delete(Node* head, int del_index){
// 	Node* traverse = head;
	
// 	if (del_index == 0){
// 		head = head->next;
// 		return head; 
// 	}
// 	for (int index = 1; index < del_index; index++){
// 	//stop one index short and check if next node to delete exeists
// 	// cout <<traverse->data << endl;
	
// 		if (traverse->next == NULL){
// 			cout << "Index out of range, no deletion carried out" << endl;
// 			return head;
// 		}
	
// 		//traverse one node short of Index to delete
// 		traverse = traverse->next;
// 	}

// 	if ((traverse->next)->next == NULL){
// 		traverse->next == NULL;
// 	}
// 	else
// 	{
// 		traverse->next = (traverse->next)->next;
// 	}

// 	return head;
// }

// void ll_display(Node * head){
// 	cout << endl << "Printing LL" << endl;
// 	while (head->next != NULL){
// 		cout<< head->data<< endl;
// 		head = head->next;
// 	}
// 	cout <<head->data << endl;
// }


// int main(){
// 	Node *head = NULL;

// 	head = ll_insert(head, 5);
// 	head = ll_insert(head, 25);
// 	head = ll_insert(head, 15);
// 	head = ll_insert(head, 65);
// 	head = ll_insert(head, 85);
// 	head = ll_insert(head, 55);
// 	head = ll_insert(head, 225);
// 	head = ll_insert(head, 195);

// 	head = ll_delete(head, 11);

// 	ll_display(head);

// 	return 0;
// }



#include<iostream>

using namespace std;


struct Node{
	int data;
	Node *next;
};

Node* ll_insert(Node* head, int number){

	if (head == NULL){
		head = new Node;
		head->data = number;
		head->next = NULL;
		return head;
	}

	Node* traverse;
	traverse = head;

	while(traverse->next != NULL){
		traverse = traverse->next;
	}

	traverse->next = new Node;
	traverse = traverse->next;
	traverse->data = number;
	traverse->next = NULL;

	return head;
}


Node * ll_swap(Node *head, int index1){

	index1--;

	int index2, count = 1;
	Node *traverse = head;
	if (head == NULL){
		cout << "empty LL" << endl;
		return head;
	}

	while (traverse->next != NULL){
		count++;
		traverse = traverse->next;
	}

	index2 = count - index1-1;
	cout << index2 << " " << count << endl;


	if (index2 == index1){
		cout<<"same index, no swap carried out"<<endl;
		return head;
	}


	if (index1 > index2){
		int swap;
		swap = index2;
		index2 = index1;
		index1 = swap; 
	}


	if (index1 == 0 && index2 == 1){
		Node *index1_main = head, *index2_main = head->next;
		Node *temp = index2_main->next;

		head = index2_main;
		index2_main->next = index1_main;
		index1_main->next = temp;

		return head;
	}


	if (index1 == 0){
		Node *index1_main = head, *index2_prior = head, *index2_main, *temp;

		for (int index = 1; index < index2; index++){
			index2_prior = index2_prior->next;
		}

		index2_main = index2_prior->next;
		temp = index2_main->next;

		index2_main->next = head->next;
		head = index2_main;

		index2_prior->next = index1_main;
		index1_main->next = temp;

		return head;
	}

	if((index2 - index1) == 1){
		Node *index1_prior = head, *index1_main, *index2_main, *temp;

		for (int index = 1; index < index1; index++){
			index1_prior = index1_prior->next;
		}

		index1_main = index1_prior->next;
		index2_main = index1_main->next;
		temp = index2_main->next;

		index1_prior->next = index2_main;
		index2_main->next = index1_main;
		index1_main->next = temp;

		return head;
	}


	Node *index1_prior = head, *index1_main = head->next; 
	Node *index2_prior = head, *index2_main, *temp;

	for (int index = 1; index < index2; index++){
		if (index < index1){
			index1_prior = index1_prior->next;
		}
		index2_prior = index2_prior->next;
	}

	// cout << index1_prior->data << " " << index2_prior->data << endl;

	index1_main = index1_prior->next;
	index2_main = index2_prior->next;
	
	index1_prior->next = index2_main;
	temp = index2_main->next;
	index2_main->next = index1_main->next;

	index2_prior->next = index1_main;
	index1_main->next = temp;

	return head;
}


void ll_display(Node * head){
	cout << endl << "Printing LL" << endl;
	while (head->next != NULL){
		cout<< head->data<< endl;
		head = head->next;
	}
	cout <<head->data << endl;
}


int main(){
	Node *head = NULL;

	head = ll_insert(head, 11);
	head = ll_insert(head, 12);
	head = ll_insert(head, 13);
	head = ll_insert(head, 14);
	head = ll_insert(head, 15);
	head = ll_insert(head, 16);
	head = ll_insert(head, 17);
	head = ll_insert(head, 18);
	head = ll_insert(head, 19);

	head = ll_swap(head, 9); 

	ll_display(head);

	return 0;
}



/* This program swaps the nodes of linked list rather
than swapping the field from the nodes.*/
// #include <bits/stdc++.h>
// using namespace std;

// /* A linked list node */
// class Node {
// public:
// 	int data;
// 	Node* next;
// };

// /* Function to swap nodes x and y in linked list by
// changing links */
// void swapNodes(Node** head_ref, int x, int y)
// {
// 	// Nothing to do if x and y are same
// 	if (x == y)
// 		return;

// 	// Search for x (keep track of prevX and CurrX
// 	Node *prevX = NULL, *currX = *head_ref;
// 	while (currX && currX->data != x) {
// 		prevX = currX;
// 		currX = currX->next;
// 	}

// 	// Search for y (keep track of prevY and CurrY
// 	Node *prevY = NULL, *currY = *head_ref;
// 	while (currY && currY->data != y) {
// 		prevY = currY;
// 		currY = currY->next;
// 	}

// 	// If either x or y is not present, nothing to do
// 	if (currX == NULL || currY == NULL)
// 		return;

// 	// If x is not head of linked list
// 	if (prevX != NULL)
// 		prevX->next = currY;
// 	else // Else make y as new head
// 		*head_ref = currY;

// 	// If y is not head of linked list
// 	if (prevY != NULL)
// 		prevY->next = currX;
// 	else // Else make x as new head
// 		*head_ref = currX;

// 	// Swap next pointers
// 	Node* temp = currY->next;
// 	currY->next = currX->next;
// 	currX->next = temp;
// }

// /* Function to add a node at the beginning of List */
// void push(Node** head_ref, int new_data)
// {
// 	/* allocate node */
// 	Node* new_node = new Node();

// 	/* put in the data */
// 	new_node->data = new_data;

// 	/* link the old list off the new node */
// 	new_node->next = (*head_ref);

// 	/* move the head to point to the new node */
// 	(*head_ref) = new_node;
// }

// /* Function to print nodes in a given linked list */
// void printList(Node* node)
// {
// 	while (node != NULL) {
// 		cout << node->data << " ";
// 		node = node->next;
// 	}
// }

// /* Driver program to test above function */
// int main()
// {
// 	Node* start = NULL;

// 	/* The constructed linked list is:
// 	1->2->3->4->5->6->7 */
// 	push(&start, 7);
// 	push(&start, 6);
// 	push(&start, 5);
// 	push(&start, 4);
// 	push(&start, 3);
// 	push(&start, 2);
// 	push(&start, 1);

// 	cout << "Linked list before calling swapNodes() ";
// 	printList(start);

// 	swapNodes(&start, 1, 3);

// 	cout << "\nLinked list after calling swapNodes() ";
// 	printList(start);

// 	return 0;
// }

// // This is code is contributed by rathbhupendra
