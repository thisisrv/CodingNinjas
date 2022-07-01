#include<stack>

bool isBalanced(string expression)
{
    // Write your code here
    stack<char> s;

    for(int i = 0; i < expression.size(); i++){

        //check if first character is closing
        if(s.size() == 0 && expression[i] == ')')
            return false;

        else if(expression[i] == '(')
            s.push(expression[i]);

        else{

            //check if element is closing bracket
            if(s.top() == '(' && expression[i] == ')')
                s.pop();
        }
    }

    if(s.empty())
        return true;
    else
        return false;
}