Node *evenAfterOdd(Node *head)
{
	//write your code here
    //create 4 pointers
    if(head == NULL)
        return head;

    Node *oddhead = NULL, *oddtail = NULL, *evenhead = NULL, *eventail = NULL;

    while(head != NULL){

        if(head -> data % 2 != 0){
            //Odd case

            if(oddhead == NULL){

                oddhead = head;
                oddtail = head;
                head = head -> next;
            }

            else{
                //if oddhead != NULL
                oddtail -> next = head;
                oddtail = head;
                head = head -> next;
            }
        }

        //Now for even case
        else{
            //Check if evenhead == NULL
            if(evenhead == NULL){

                evenhead = head;
                eventail = head;
                head = head -> next;
            }

            else{
                //if evenhead != NULL
                eventail -> next = head;
                eventail = head;
                head = head -> next;
            }
        }
    }

    //Make both tail NULL
    if(oddtail != NULL)
        oddtail -> next = NULL;

    if(eventail != NULL)
        eventail -> next = NULL;

    //Attatch both ll
    if(oddhead == NULL)
        return evenhead;

    else if(evenhead == NULL)
        return oddhead;

    oddtail -> next = evenhead;
    return oddhead;

}