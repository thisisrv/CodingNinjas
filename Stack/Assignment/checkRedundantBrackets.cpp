bool checkRedundantBrackets(string expression) {
	// Write your code here
    //create stack
    stack<char> s;

    //Traverse string
    for(int i =0; i < expression.size(); i++){

        //if element is )
        if(expression[i] == ')'){

            //create a count variable
            int count = 0;

            //count elements within brackets
            while(s.top() != '('){
                count++;
                s.pop();
            }

            //check count values
            if(count == 0 || count == 1)
                return true;

            if(s.size() != 0)
                s.pop();
        }

        //Else Push into stack
        else{
            s.push(expression[i]);
        }
    }

    //If came out of loop that means no redundant bracket found
    return false;

}