


ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *traverse = head;
        int count = 1, node_del;

        while(traverse->next != NULL) {
        	traverse = traverse->next;
        	count ++;
        }

        node_del = count - n + 1;

        count = 0;

        ListNode *prior, *main;

        for (int index = 0; index < node_del; index++) {}
    }