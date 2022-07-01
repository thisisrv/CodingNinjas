void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    //Base case
    if(input.size() == 1 || input.size() == 0)
        return;

    //Rec call
    int last_element = input.top();
    input.pop();
    reverseStack(input, extra);

    //Small calc
    //Copy all elements from input to extra
    while(input.size() != 0){

        extra.push(input.top());
        input.pop();
    }

    //add last_element in input stack
    input.push(last_element);

    //add all elements from extra to input stack
    while(extra.size() != 0){

        input.push(extra.top());
        extra.pop();
    }

}