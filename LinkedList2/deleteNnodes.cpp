
Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
    if(head == NULL)
	    return head;

    if(M == 0)
        return NULL;

    if(N == 0)
        return head;

	Node *t1 = head, *t2 = NULL;

	int count1 = 1, count2 = 1;

	while(t1 != NULL){

	    while(t1 != NULL && count1 < M){
	        count1 ++;
	        t1 = t1 -> next;
	    }

	    if(t1 == NULL || t1 -> next == NULL)
	        return head;

	    t2 = t1 -> next;

	    while(t2 != NULL && count2 < N){
	        Node *t = t2;
	        t2 = t2 -> next;
	        count2++;
	        delete t;
	    }

	    if(t2 == NULL){
	        t1 -> next = t2;
	        t1 = t2;
	        return head;
	    }

	    Node *t = t2;
	    t2 = t2 -> next;
	    delete t;

	    t1 -> next = t2;
	    t1 = t2;

	    count1 = 1;
	    count2 = 1;
	}

	return head;
}