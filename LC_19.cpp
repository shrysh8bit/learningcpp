


ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count= 0;
        ListNode* temp = head;
        
        
        
        while(temp != NULL){
            temp = temp->next;
            count++;
        }

        if(count == 1) return NULL;
        if(count == n) return head->next;
        
        temp = head;
        for ( int i = 1; i < count - n; i++){
            temp = temp->next;
        }
        
        temp->next = temp->next->next;
        
        return head;
        
    }
