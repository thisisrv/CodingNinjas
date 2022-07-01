void reverseQueue(queue<int> &input) {

    //Base case
    if(input.size() == 1 || input.size() == 0)
        return ;

    //Rec call
    int first_element = input.front();
    input.pop();
    reverseQueue(input);

    //Small calc
    input.push(first_element);
}