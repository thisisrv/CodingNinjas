using namespace std;
class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;

    public:

    //Create constructor;
    StackUsingArray(int totalsize){
        data = new int[totalsize];
        nextIndex = 0;
        capacity = totalsize;
    }

    //Return size of stack
    int size(){
        return nextIndex;
    }

    //return true is stack is empty
    bool isempty(){
        if(nextIndex == 0)
            return true;
        else
            return false;
    }

    //Insert element in stack
    void push(int element){
        //check if stack is full
        if(nextIndex == capacity){
            cout << "Stack is full" << endl;
            return;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    //Delete element in stack
    int pop(){
        if(isempty()){
            cout << "Stack is empty" << endl;
            return -1;
        }

        nextIndex--;
        return data[nextIndex];
    }

    //Return top element
    int top(){
        if(isempty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return data[nextIndex - 1];
    }

};