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


#include<iostream>

using namespace std;

struct Node{
	int data;
	Node *next;
};

void enter_values(Node **start, int number){

	// Node *temp = new Node;

	if (*start == NULL){
		*start = new Node;
		(*start)->data = number;
		(*start)->next = NULL;

		return;
	}

	Node *lead = *start;

	while (lead->next != NULL && (lead->next)->data < number){
		lead = lead->next;
	}

	Node *temp = new Node;
	
	temp->next = lead->next;
	temp->data = number;
	lead->next = temp;
	

	return;
}

void read_values(Node *start){
		Node *traverse;
		traverse = start;

	while(traverse != NULL){
		cout << traverse->data << endl;
		traverse = traverse->next;
	}
}

int main(){
	Node *start = NULL;

	enter_values(&start, 5);
	enter_values(&start, 15);
	enter_values(&start, 25);
	enter_values(&start, 20);
	
	read_values(start);



return 0;

}