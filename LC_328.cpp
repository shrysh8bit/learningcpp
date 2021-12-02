 #include <iostream>

using namespace std;

struct List {
	int val;
	List* next;
};

List* oddeven(List* head){
	if ( head == NULL || head->next == NULL){
            return head;
        }
        
    List *odd = head, *even = head->next, *even_static = head->next;
    
    while( ((even->next) != NULL) && ((even->next)->next != NULL)){
        odd->next = even->next;
        even->next = (even->next)->next;
        odd = odd->next;
        odd->next = even_static;
        even = even->next;
    }
    
    if(even->next ==NULL){
        return head;
    }
    
    odd->next = even->next;
    odd->next->next = even_static;
    even->next = NULL;
    return head;
}

int main(){
	List* head;

	head = new List;
	
	for (int i=1; i<=5; i++){
		
		head->val = i;
		head->next = new List;
	}

	head = oddeven(head);

	

	return 0;
}




 
