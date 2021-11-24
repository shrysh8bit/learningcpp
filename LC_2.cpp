ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int count, carry = 0;
    ListNode *l1_last;

    while (l1 != NULL || l2 != NULL){

       	if (l1->next == NULL){
    		l1_last = l1;
    	}

	    count = carry;

	    if( l1 != NULL ){
	    	count += l1->val;
	    	l1 = l1->next;
	    }
	    else{
	    	l1_last->next = l2;
	    	l1 = l2;
	    	l2 = null;
	    }


	    if (l2 != NULL ){
	    	count += l2->val;
	    	l2 = l2->next;
	    }

	    carry = count/10;
	    count = count%10;

	    
	    l1->val = count;

    }
     	
    if (carry > 0){
    	l1->next = new ListNode;
    	l1 = l1->next;
    	l1->val = carry;
    	l1->next = NULL;
    }

    return sum;

}